%% Definitions
% PCoGV - planar (x&y) center of gravity velocity
% CCSA  - center column steering angle
% TOY   - time optimal yaw

%% Startup
% Run startup.m before running this file. Run Track_Tables after running
% this file
clearvars -except S1 S2 S3 S4 deg2rad l steer_slope CENTER_STEER_ANGLE_MAX ALL_SWEEP_DATA out sim
clc

load("Simulation_Data_Input\PROCESSED_DATA\Sweep_Tables.mat");

%% Parameters
max_steering_vel = 22; % m/s
dv = 0.5; % m/s
ds = 5; % deg
dy = 0.05; % rad/s
n = 3;

%% Simulation Conditions & Data
Digital_Signals = out.Digital_Signals;
Vehicle_Signals = out.Vehicle_Signals;
Driver_signals = out.Driver_Signals;

steering_ref = ALL_SWEEP_DATA.ccw_steering(:,2);

num2 = sum(steering_ref == 0) / 2;
num3 = length(steering_ref) / num2;

velocity_grid = reshape(ALL_SWEEP_DATA.ccw_steering(:,1), [num3 num2]);
yaw_rate_grid = reshape(ALL_SWEEP_DATA.ccw_steering(:,2), [num3 num2]);

%% Extract Raw Data
% torques = Vehicle_Signals.trn.motor_torque>Data(:,4);

theta = Digital_Signals.Corner_Dynamics_Sensors.theta.Data;
omega_m = Driver_signals.Omega.Data;
yaw_rates = Driver_signals.r.Data;
xdot = Driver_signals.Vel.xdot.Data;
ydot = Driver_signals.Vel.ydot.Data;

battery_I = Digital_Signals.Power_Sensors.batt_I.Data;
battery_V = Digital_Signals.Power_Sensors.batt_V.Data;

counter = out.Sweep_Generator.counter.Data;

%% Process Raw Data into Clean Data
end_positions = [find(counter == 0); length(counter)];  % indicies for the end of each PCoGV & CCSA setpoint
omega_mean = mean([omega_m(:,3) omega_m(:,4)], 2); % mean rear tires angular velocity (rad/s)
velocities = sqrt(xdot.^2 + ydot.^2);      % vehicle PCoGV (m/s)

yaw_rate = reshape(yaw_rates(end_positions), [num3 num2]);
velocity = reshape(velocities(end_positions), [num3 num2]);
steering = reshape(theta(end_positions), [num3 num2]);
%torque = reshape(torques(end_positions), [num3 num2]);
%power_OUT = reshape(torques(end_positions) .* omega_mean(end_positions), [num3 num2]);
power_IN = reshape(battery_I(end_positions) .* battery_V(end_positions), [num3 num2]);

%% Calculate All RAW Lookup Tables
[max_yaw_v, ~] = max(yaw_rate);
[max_yaw_s, ~] = max(yaw_rate,[],2);
limit_velocity = velocity(1,:);
limit_steering = steering(:,1);

max_v_bp = min(limit_velocity):dv:max(limit_velocity);
max_v_bp2 = max_v_bp(n:end);
max_s_bp = min(limit_steering):ds:max(limit_steering);
max_y_bp = min(yaw_rate(:)):dy:max(yaw_rate(:));
[limit_velocity_grid, limit_steering_grid] = meshgrid(max_v_bp,max_s_bp);
[limit_velocity_grid2, limit_yaw_rate_grid] = meshgrid(max_v_bp,max_y_bp);

% calculate max allow yaw rate given velocity
[xData, yData] = prepareCurveData( limit_velocity, max_yaw_v );
ft = 'pchipinterp';
[fitresult1, gof] = fit( xData, yData, ft, 'Normalize', 'on' );

% calculate max allowed steering angle given max allowed yaw rate
[xData, yData] = prepareCurveData( max_yaw_s, limit_steering );
ft = fittype( 'smoothingspline' );
opts = fitoptions( 'Method', 'SmoothingSpline' );
opts.SmoothingParam = 0.99999;
[fitresult2, gof] = fit( xData, yData, ft, opts );

% calculate overall lookup table
[xData, yData, zData] = prepareSurfaceData( velocity, steering, yaw_rate );
ft = 'linearinterp';
[fitresult3, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );

%% Minimum Turning Radius
max_yaw_table = feval(fitresult1, max_v_bp);
max_theta_table = feval(fitresult2, max_yaw_table);
max_yaw_table_ref = feval(fitresult3, limit_velocity_grid,limit_steering_grid);

[max_theta, max_theta_idx] = max(max_theta_table);
critical_velocity = max_v_bp(max_theta_idx);
critical_radius = max_v_bp(n:end) ./ max_yaw_table(n:end)';

max_steering = (ones(1,length(max_v_bp)).*sim.range.CENTER_STEER_ANGLE_MAX).*(max_v_bp < critical_velocity);
normal_steering = max_theta_table' .* (max_v_bp >= critical_velocity);

max_theta_table = min(sim.range.CENTER_STEER_ANGLE_MAX,max_steering + normal_steering);

yaw_rate_table = max_yaw_table_ref.*((gradient(max_yaw_table_ref) >= 0) & (limit_velocity_grid < max_steering_vel));
yaw_rate_table(yaw_rate_table==0) = nan;

[xData, yData, zData] = prepareSurfaceData( limit_velocity_grid, yaw_rate_table, limit_steering_grid );
ft = 'linearinterp';
[fitresult4, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );

[xData, yData] = prepareCurveData( critical_radius, max_v_bp2 );
ft = 'pchipinterp';
[fitresult5, gof] = fit( xData, yData, ft, 'Normalize', 'on' );

steering_angle_table = feval(fitresult4, limit_velocity_grid2, limit_yaw_rate_grid);
steering_angle_table(1,:) = 0;

%% TOY Bias (adjusting vehicle yaw rate to improve performance)
% x = steering.*steer_slope; % rack displacement (m)
% theta_left = deg2rad.*((S1*x.^3) - (S2*x.^2) + (S3.*x) - S4); % front left tire angle (rad)
% theta_right = deg2rad.*((S1*x.^3) + (S2*x.^2) + (S3.*x) + S4); % front right tire angle (rad)
% theta_avg = mean([theta_left; theta_right]); % mean front tire angles (rad)
% 
% yaw_rate_TOY = velocity .* theta_avg ./ sum(l); % TOY (rad/s)
% TOY_error = yaw_rate_TOY - yaw_rate; % error between vehicle steady state yaw, and correspond TOY at the same PCoGV & CCSA
% 
% %% Final Calculations
% skidpad_radius = 7.5.*ones(num3, num2); % m
% vehicle_e = power_OUT ./ power_IN; % vehicle overall power efficiency
% radius = velocity ./ yaw_rate; % vehicle turning radius as function of PCoGV & CCSA

%% Populate TVS Struct
tvs.yaw_control.max_v_bp = max_v_bp;
tvs.yaw_control.max_s_bp = max_s_bp;
tvs.yaw_control.max_yaw_table_ref = max_yaw_table_ref;

driver.control.max_v_bp = max_v_bp;
driver.control.max_s_bp = max_s_bp;
driver.control.max_y_bp = max_y_bp;
driver.control.steering_angle_table = steering_angle_table;
driver.control.max_yaw_table = max_yaw_table;
driver.control.max_theta_table = max_theta_table;

%% Cleaning up & Saving
clearvars -except tvs driver fitresult5

save("PROCESSED_DATA\TVS_Tables.mat", "tvs");
save("PROCESSED_DATA\Driver_Tables.mat", "driver");
save("PROCESSED_DATA\Yaw_Tables.mat", "fitresult5");

%% Data Viewing
% scatter3(limit_velocity_grid,limit_steering_grid,max_yaw_table_ref)
% scatter3(max_yaw_bp,max_theta_table,max_yaw_table);hold on;scatter3(velocity(:), steering(:), yaw_rate(:))
% scatter3(velocity(:), steering(:), yaw_rate_TOY(:))
% scatter3(velocity(:), steering(:), TOY_error(:))
% scatter3(velocity(:), steering(:), TOY_correction_table(:))

% xlabel("Velocity (m/s)")
% ylabel("Steeting Angle (deg)")
% zlabel("Yaw Rate (rad/s)")

% xlabel("Planar CoG Velocity (m/s)")
% ylabel("Center Column Steering Angle (deg)")
% zlabel("Planar Vehicle Yaw Rate (rad/s)")

% scatter3(velocity(:), steering(:), power_IN(:))
% scatter3(velocity(:), steering(:), power_OUT(:))
% xlabel("Planar CoG Velocity (m/s)")
% ylabel("Center Column Steering Angle (deg)")
% zlabel("Battery Output Power (W)")

% scatter3(velocity(:), steering(:), vehicle_e(:))
% scatter3(velocity(:), steering(:), radius(:))
% hold on
% scatter3(velocity(:), steering(:), skidpad_radius(:)
