%% Definitions
% PCoGV - planar (x&y) center of gravity velocity
% CCSA  - center column steering angle
% TOY   - time optimal yaw

%% Startup
% Run startup.m before running this file, ensure sweep_data.mat is up to date)
clearvars -except S1 S2 S3 S4 deg2rad l steer_slope MAX_V MIN_V dv d0 CENTER_STEER_ANGLE_MAX ALL_SWEEP_DATA TOY_correction_factor
clc
load("sweep_data.mat")
load("PROCESSED_DATA\Sweep_Tables.mat");

%% Simulation Conditions
num1 = 392; % total number of data points collected, including buffer points
steering = ALL_SWEEP_DATA.ccw_steering(1:num1,2); % ordered CCSA setpoints used in simulation (deg)

%% Lookup Table Breakpoints (sweep steering angle at set velocity, increase velocity, repeat)
velocity_sweep = MIN_V:dv:MAX_V; % PCoGV sweep used in simulation
steering_sweep = 0:d0:CENTER_STEER_ANGLE_MAX; % CCSA sweep used in simulation
yaw_rate_sweep = 0:0.05:2; % vehicle body yaw rate (rad/s)
num2 = length(velocity_sweep);
num3 = length(steering_sweep);
num4 = length(yaw_rate_sweep);

[velocity_grid, yaw_rate_grid] = meshgrid(velocity_sweep, yaw_rate_sweep);

%% Initialize Variables
yaw_rate = ones(1, num1);  % measured vehicle yaw rate in simulation order
torque = ones(1, num1);    % measured tvs torque request in simulation order
power_OUT = ones(1, num1); % measured vehicle output power in simulation order
power_IN = ones(1, num1);  % measured vehicle input power in simulation order
velocity = ones(1, num1);  % measured vehicle PCoGV in simulation order

%% Extract Raw Data
% rear right TVS Torque request (Nm)
torques = squeeze(out.logsout{1}.Values.T.Data(1, 4, :));

% rear left & rear right motor shaft angular velocity (rad/s)
omega_ml = squeeze(out.logsout{1}.Values.omega_m.Data(1, 3, :));
omega_mr = squeeze(out.logsout{1}.Values.omega_m.Data(1, 4, :));

% counter tracking time duration of each PCoGV & CCSA setpoint
Counter = out.logsout{2}.Values.Data;

% All sensor inputs to control systems
Digital_Signals = out.logsout{3}.Values;

% measured vehicle body yaw rate (rad/s)
yaw_rates = Digital_Signals.Navigation_Sensors.ang_vel.Data(:,3);

% measured battery current (A)
battery_I = Digital_Signals.Power_Sensors.battery_I.Data;

% measured battery voltage (V)
battery_V = Digital_Signals.Power_Sensors.battery_V.Data;

% measured longgitudinal & lateral CoG velocity (m/s)
xdot = Digital_Signals.Navigation_Sensors.vel.Data(:,1);
ydot = Digital_Signals.Navigation_Sensors.vel.Data(:,2);

%% Process Raw Data into Clean Data
end_positions = find(Counter == 0);        % indicies for the end of each PCoGV & CCSA setpoint
omega_mean = mean([omega_ml omega_mr], 2); % mean rear tires angular velocity (rad/s)
velocities = sqrt(xdot.^2 + ydot.^2);      % vehicle PCoGV (m/s)

% iterate through each PCoGV & CCSA setpoint, extract & order data by defined PCoGV & CCSA breakpoints
for i = 1:num1
    if (mod(i, num3+1) == 1)
        yaw_rate(i) = 0;
        torque(i) = torques(end_positions(i));
        velocity(i) = velocities(end_positions(i));
        power_OUT(i) = torque(i) * omega_mean(end_positions(i));
        power_IN(i) = battery_I(end_positions(i)) * battery_V(end_positions(i));
    elseif (mod(i, num3+1) > 1)
        yaw_rate(i) = yaw_rates(end_positions(i));
        torque(i) = torques(end_positions(i));
        velocity(i) = velocities(end_positions(i));
        power_OUT(i) = torque(i) * omega_mean(end_positions(i));
        power_IN(i) = battery_I(end_positions(i)) * battery_V(end_positions(i));
    else
        velocity(i) = 1;
        steering(i) = 1;
    end
end

% remove unwanted PCoGV & CCSA setpoints
yaw_rate = yaw_rate(find(yaw_rate~=1));
velocity = velocity(find(velocity~=1));
steering = steering(find(steering~=1));
torque = torque(find(torque~=1));
power_OUT = power_OUT(find(power_OUT~=1));
power_IN = power_IN(find(power_IN~=1));

%% Reshape Data (to conform with 2D lookup table convention)
yaw_rate = reshape(yaw_rate, [num3 num2]);
velocity = reshape(velocity, [num3 num2]);
steering = reshape(steering, [num3 num2]);
torque = reshape(torque, [num3 num2]);
power_OUT = reshape(power_OUT, [num3 num2]);
power_IN = reshape(power_IN, [num3 num2]);

%% Yaw Rate Gradient
yaw_rate_gradient = ones(num3, num2);
peaks = num3.*ones(1, num2);

% find slope of yaw rate curve
for i = 1:num2
    for j = 1:num3
        if j == 1
            yaw_rate_gradient(j, i) = 1;
        elseif j == num3
            yaw_rate_gradient(j, i) = -1;
        else
            slope_lower = yaw_rate(j, i) - yaw_rate(j-1, i);
            slope_upper = yaw_rate(j+1, i) - yaw_rate(j, i);

            yaw_rate_gradient(j, i) = sign(slope_upper + slope_lower);

            if ((sign(slope_lower) + sign(slope_upper)) == 0)
                peaks(i) = j;
            end
        end
    end
end

% split yaw rate curve into 2 pieces
yaw_rate_Up = yaw_rate(yaw_rate_gradient > 0);
steering_Up = steering(yaw_rate_gradient > 0);
velocity_Up = velocity(yaw_rate_gradient > 0);

yaw_rate_Dn = yaw_rate(yaw_rate_gradient < 0);
steering_Dn = steering(yaw_rate_gradient < 0);
velocity_Dn = velocity(yaw_rate_gradient < 0);

% fitting TOY close data
[xData, yData, zData] = prepareSurfaceData(yaw_rate_Up, velocity_Up, steering_Up);
ft = fittype('loess');
[fitresult, gof] = fit([xData, yData], zData, ft, 'Normalize', 'on');

steering_Up_Grid = reshape(feval(fitresult,[yaw_rate_grid(:),velocity_grid(:)]), [num4, num2]);

% fitting understeering data
[xData, yData, zData] = prepareSurfaceData(yaw_rate_Dn, velocity_Dn, steering_Dn);
ft = fittype('loess');
[fitresult, gof] = fit([xData, yData], zData, ft, 'Normalize', 'on');

steering_Dn_Grid = reshape(feval(fitresult,[yaw_rate_grid(:),velocity_grid(:)]), [num4, num2]);

%% TOY Bias (adjusting vehicle yaw rate to improve performance)
x = steering_sweep.*steer_slope; % rack displacement (m)
theta_left = deg2rad.*((S1*x.^3) - (S2*x.^2) + (S3.*x) - S4); % front left tire angle (rad)
theta_right = deg2rad.*((S1*x.^3) + (S2*x.^2) + (S3.*x) + S4); % front right tire angle (rad)
theta_avg = mean([theta_left; theta_right])' * ones(1, num2); % mean front tire angles (rad)

yaw_rate_TOY = velocity .* theta_avg ./ sum(l); % TOY (rad/s)
TOY_error = yaw_rate_TOY - yaw_rate; % error between vehicle steady state yaw, and correspond TOY at the same PCoGV & CCSA

% calculate minimum TOY adjustment for all PCoGV & CCSA between TOY_error, and nominal value (TOY_correction_factor)
possible_corrections = [abs(TOY_error(:)) (TOY_correction_factor.*ones(num3*num2,1))]'; % 
TOY_correction_table = sign(TOY_error(:)).*min(possible_corrections)';
TOY_correction_table = reshape(TOY_correction_table, [num3, num2]);

%% Final Calculations
skidpad_radius = 7.5.*ones(num3, num2); % m
vehicle_e = power_OUT ./ power_IN; % vehicle overall power efficiency
radius = velocity ./ yaw_rate; % vehicle turning radius as function of PCoGV & CCSA

%% Cleaning up & Saving
clearvars -except steering_sweep velocity_sweep yaw_rate_sweep yaw_rate TOY_correction_table steering_Up_Grid steering_Dn_Grid yaw_rate_gradient

save("..\PROCESSED_DATA\Yaw_Tables.mat")

%% Data Viewing
% scatter3(velocity(:), steering(:), yaw_rate(:))
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
% scatter3(velocity(:), steering(:), skidpad_radius(:))

% scatter3(velocity(:), steering(:), yaw_rate_gradient(:))

% scatter3(velocity_grid(:), yaw_rate_grid(:), steering_Dn_Grid(:))
% scatter3(velocity_grid(:), yaw_rate_grid(:), steering_Up_Grid(:))
% scatter3(velocity_Up(:), steering_Up_Grid(:), yaw_rate_Up(:))