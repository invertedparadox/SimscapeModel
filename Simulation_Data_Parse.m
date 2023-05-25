%% Extract Bus Data
TV_OUTPUT = out.TV_Output;
Reference_Signals = out.Navigation_Reference;
Fused_Signals = out.Sensor_Fused;
Reference_Generator = out.Reference_Generator;
Digital_Signals = out.Digital_Signals;
Lookup_Steering = out.lookup_steering;
time = Digital_Signals.Navigation_Sensors.gyro.Time;
time_15 = TV_OUTPUT.ub.Time;
Vehicle = out.Vehicle_Signals;
throttle = out.Throttle.Data(:);

%% Vehicle Dynamics
yaw_rates = Reference_Signals.Chassis_AngularVelocity.Data(:,3);
ref_yaw_rates = TV_OUTPUT.ref_yaw.Data;
steering_ss = Lookup_Steering.Data;

X = Reference_Signals.Chassis_Position.X.Data(:);
Y = Reference_Signals.Chassis_Position.Y.Data(:);

ax = Reference_Signals.Chassis_Acceleration_VNED.ax.Data(:);
ay = Reference_Signals.Chassis_Acceleration_VNED.ay.Data(:);
az = Reference_Signals.Chassis_Acceleration_VNED.az.Data(:);

steering_10 = Reference_Signals.theta.Data(:);

Acceleration_REF = [ax, ay, az];

X_ref = Reference_Generator.x_ref.Data;
Y_ref = Reference_Generator.y_ref.Data;

omega = squeeze(Digital_Signals.Corner_Dynamics_Sensors.omega.Data)';
Fz = Digital_Signals.Corner_Dynamics_Sensors.FZ.Data;
steer = Digital_Signals.Corner_Dynamics_Sensors.theta.Data;

%% TVS
flag = TV_OUTPUT.bigM_flag.Data;
windup = TV_OUTPUT.windup.Data;

torque_out = squeeze(TV_OUTPUT.Tx.Data)';
TxFL = torque_out(:,1);
TxFR = torque_out(:,2);
TxRL = torque_out(:,3);
TxRR = torque_out(:,4);

ub_torque = TV_OUTPUT.ub.Data;
lb_torque = TV_OUTPUT.lb.Data;

ang_acc = TV_OUTPUT.beq.Data;
% pre_limit_ang_acc = out.pre_limit_ang_acc.Data;
max_ang_acc = TV_OUTPUT.max_ang_acc.Data;
min_ang_acc = TV_OUTPUT.min_ang_acc.Data;

batt_I = Digital_Signals.Power_Sensors.battery_I.Data;
batt_V = Digital_Signals.Power_Sensors.battery_V.Data;
driver_power_req = TV_OUTPUT.b.Data;

obj_gain = TV_OUTPUT.obj_gain.Data;

% throttle = TV_OUTPUT.b.Data(:) ./ ABS_MAX_TRQ_CMD;

%% Power Statistics
current_limits = squeeze(Digital_Signals.Power_Sensors.pwr_lmt.Data);
motor_current = squeeze(Digital_Signals.Power_Sensors.motor_I.Data)';

%% Error Terms
yaw_error = out.yaw_error.Data;
dis_error = Reference_Generator.d_error.Data;
rad_error = Reference_Generator.r_error.Data;
psi_error = Reference_Generator.psi_error.Data;
ang_acc_error = ang_acc;

%% Navigation Signals
% position
PositionX_REF = Reference_Signals.Chassis_Position.X.data(:);
PositionY_REF = Reference_Signals.Chassis_Position.Y.data(:);
PositionZ_REF = Reference_Signals.Chassis_Position.Z.data(:);
Position_REF = [PositionX_REF PositionY_REF PositionZ_REF];
Position_FUS = squeeze(Fused_Signals.pos_VNED.Data)';

pos_error = Position_REF - Position_FUS;
pos_norm_error = vecnorm(pos_error');

% orientation
Orientation_REF = squeeze(Reference_Signals.Chassis_Orientation.Data);
Orientation = quaternion(squeeze(Fused_Signals.ang_NED.data)');
Orientation_FUS = euler(Orientation, 'XYZ', 'frame');

ang_error = rad2deg(Orientation_REF - Orientation_FUS);
ang_error = ang_error + ((ang_error > 350).*-360) + ((ang_error < -350).*360);
ang_norm_error = vecnorm(ang_error');

% angular velocity
AngularVelocity_p_REF = Reference_Signals.Chassis_AngularVelocity.Data(:,1);
AngularVelocity_q_REF = Reference_Signals.Chassis_AngularVelocity.Data(:,2);
AngularVelocity_r_REF = Reference_Signals.Chassis_AngularVelocity.Data(:,3);
AngularVelocity_REF = [AngularVelocity_p_REF AngularVelocity_q_REF AngularVelocity_r_REF];
AngularVelocity_FUS = squeeze(Fused_Signals.angvel_VNED.Data)';

ang_vel_error = AngularVelocity_REF - AngularVelocity_FUS;
ang_vel_norm_error = vecnorm(ang_vel_error');

% velocity
Velocity_X_REF = Reference_Signals.Chassis_Velocity_VNED.xdot.data(:,1);
Velocity_Y_REF = Reference_Signals.Chassis_Velocity_VNED.ydot.data(:,1);
Velocity_Z_REF = Reference_Signals.Chassis_Velocity_VNED.zdot.data(:,1);
Velocity_REF = [Velocity_X_REF Velocity_Y_REF Velocity_Z_REF];
Velocity_FUS = squeeze(Fused_Signals.vel_VNED.Data);

vel_error = Velocity_REF - Velocity_FUS;
vel_norm_error = vecnorm(vel_error');

Velocity_PCoG = vecnorm([Velocity_X_REF,Velocity_Y_REF]');

%% Simulation Validation
figure(1)

% position
subplot(2,2,1)
plot(Y_ref, X_ref)
hold on
plot(Y, X)

xlabel("Position Y (m)")
ylabel("Position X (m)")
legend("Reference","Actual")

% steering
subplot(2,2,2)
plot(time_15, steer)
hold on
plot(time_15, steering_ss)

xlabel("time (s)")
ylabel("Steering Angle (deg)")
legend("Actual", "Steady State")

% omega
subplot(2,2,3)
plot(time_15, omega(:,1))
hold on
plot(time_15, omega(:,2))
hold on
plot(time_15, omega(:,3))
hold on
plot(time_15, omega(:,4))

xlabel("time (s)")
ylabel("Wheel Speed (rad/s)")
legend("FL","FR","RL","RR")

% Fz
subplot(2,2,4)
plot(time_15, Fz(:,1))
hold on
plot(time_15, Fz(:,2))
hold on
plot(time_15, Fz(:,3))
hold on
plot(time_15, Fz(:,4))

xlabel("time (s)")
ylabel("Normal Force (N)")
legend("FL","FR","RL","RR")

%% Plotting TVS
figure(2)

% torque request
subplot(2,2,1)
plot(time_15, TxFL)
hold on
plot(time_15, TxFR)
hold on
plot(time_15, TxRL)
hold on
plot(time_15, TxRR)

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("FL Torque","FR Torque","RL Torque","RR Torque")

% control signal
% subplot(2,2,2)
% plot(time_15,ang_acc)
% hold on
% plot(time_15, pre_limit_ang_acc)
% hold on
% plot(time_15, max_ang_acc)
% hold on
% plot(time_15, min_ang_acc)
% 
% xlabel("time (s)")
% ylabel("Angular Acceleration (rad/s^2)")
% legend("Actual","Pre Limit", "MAX", "MIN")

% objective gain coefficients
subplot(2,2,3)
plot(time_15, obj_gain(:,1))
hold on
plot(time_15, obj_gain(:,2))
hold on
plot(time_15, obj_gain(:,3))
hold on
plot(time_15, obj_gain(:,4))

xlabel("time (s)")
ylabel("Optimization Weight")
legend("FL", "FR", "RL", "RR")

% yaw rate request
subplot(2,2,4)
plot(time_15, ref_yaw_rates)
hold on
plot(time, yaw_rates)

xlabel("time (s)")
ylabel("Yaw Rate (rad/s)")
legend("Reference","Actual")

%% Plotting Torque Request Individually
figure(3)

% FL torque
subplot(2,2,1)
plot(time_15, TxFL)
hold on
plot(time_15, ub_torque(:,1))
hold on
plot(time_15, lb_torque(:,1))

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("FL Torque","Upper Torque","Lower Torque")

% FR torque
subplot(2,2,2)
plot(time_15, TxFR)
hold on
plot(time_15, ub_torque(:,2))
hold on
plot(time_15, lb_torque(:,2))

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("FR Torque","Upper Torque","Lower Torque")

% RL torque
subplot(2,2,3)
plot(time_15, TxRL)
hold on
plot(time_15, ub_torque(:,3))
hold on
plot(time_15, lb_torque(:,3))

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("RL Torque","Upper Torque","Lower Torque")

% RR torque
subplot(2,2,4)
plot(time_15, TxRR)
hold on
plot(time_15, ub_torque(:,4))
hold on
plot(time_15, lb_torque(:,4))

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("RR Torque","Upper Torque","Lower Torque")

%% Power Statistics
figure (4)

% battery voltage
subplot(2,2,1)
plot(time_15, batt_V)

xlabel("time (s)")
ylabel("Voltage (V)")

% current
subplot(2,2,2)
plot(time_15, batt_I)
hold on
plot(time_15, current_limits(:,1))
hold on
plot(time_15, current_limits(:,2))
hold on
plot(time_15, motor_current(:,1))
hold on
plot(time_15, motor_current(:,2))
hold on
plot(time_15, motor_current(:,3))
hold on
plot(time_15, motor_current(:,4))

xlabel("time (s)")
ylabel("Current (A)")
legend("Actual", "DCL", "CCL", "FL I", "FR I", "RL I", "RR I")

% power consumption
subplot(2,2,3)
plot(time_15, batt_V.*batt_I)

xlabel("time (s)")
ylabel("Power (W)")
legend("Reference","Actual")

subplot(2,2,4)
% Battery SOC

%% Driver Error Checking
figure(5)

% track distance error
subplot(2,2,1)
plot(time_15, dis_error)

xlabel("time (s)")
ylabel("Distance (m)")

% track yaw error
subplot(2,2,2)
plot(time_15, yaw_error)

xlabel("time (s)")
ylabel("Yaw Rate (rad/s)")

% track orientation error
subplot(2,2,3)
plot(time_15, psi_error)

xlabel("time (s)")
ylabel("Angle (rad)")

% track turning radius error
subplot(2,2,4)
plot(time_15, rad_error)

xlabel("time (s)")
ylabel("Turning Radius (m)")

%% SFS Error Checking
figure(6)

% position error
subplot(2,2,1)
plot(time, pos_error(:,1))
hold on
plot(time, pos_error(:,2))
hold on
plot(time, pos_error(:,3))
hold on
plot(time, pos_norm_error)

xlabel("time (s)")
ylabel("Distance (m)")
legend("X", "Y", "Z", "Mag")

% orientation error
subplot(2,2,2)
plot(time, ang_error(:,1))
hold on
plot(time, ang_error(:,2))
hold on
plot(time, ang_error(:,3))
hold on
plot(time, ang_norm_error)

xlabel("time (s)")
ylabel("Angle (deg)")
legend("X", "Y", "Z", "Mag")

% angular velocity error
subplot(2,2,3)
plot(time, ang_vel_error(:,1))
hold on
plot(time, ang_vel_error(:,2))
hold on
plot(time, ang_vel_error(:,3))
hold on
plot(time, ang_vel_norm_error)

xlabel("time (s)")
ylabel("Angular Rate (rad/s)")
legend("X", "Y", "Z", "Mag")

% velocity error
subplot(2,2,4)
plot(time, vel_error(:,1))
hold on
plot(time, vel_error(:,2))
hold on
plot(time, vel_error(:,3))
hold on
plot(time, vel_norm_error)

xlabel("time (s)")
ylabel("Velocity (m/s)")
legend("X", "Y", "Z", "Mag")

%% TVS Error Checking
figure(7)

% Optimization Success Flag
subplot(2,2,1)
plot(time_15, flag)

xlabel("time (s)")
ylabel("State")
legend("Optimization Flag")

% Yaw Controller Reset
% subplot(2,2,2)
% plot(time_15, reset)
% 
% xlabel("time (s)")
% ylabel("State")
% legend("Integral Reset")

% Yaw Controller Windup
subplot(2,2,3)
plot(time_15, windup)

xlabel("time (s)")
ylabel("State")
legend("Integral Windup")

subplot(2,2,4)
% something with traction control

%% Bulk Vehicle Dynamics Data
figure(8)
subplot(2,2,1)
plot(time, rad2deg(Orientation_REF))

xlabel("time (s)")
ylabel("Orientation (deg) (NED)")
legend("N", "E", "D")

subplot(2,2,2)
plot(time, Velocity_REF)

xlabel("time (s)")
ylabel("Velocity (m/s) (VNED)")
legend("N", "E", "D")

subplot(2,2,3)
plot(time, AngularVelocity_REF)

xlabel("time (s)")
ylabel("Angular Velocity (rad/s) (VNED)")
legend("N", "E", "D")

subplot(2,2,4)
plot(time, Acceleration_REF)

xlabel("time (s)")
ylabel("Accelertion (m/s^2) (VNED)")
legend("N", "E", "D")

%% Vehicle Dynamics Evaluation
figure(9)

% g-g diagram
subplot(2,2,1)
plot(ay,ax)

xlabel("Lateral Acceleration (m/s^2)")
ylabel("Longitudinal Acceleration (m/s^2)")

% Turning Diagram
subplot(2,2,2)
scatter3(steering_10, Velocity_PCoG, yaw_rates)

xlabel("Steering Angle (deg)")
ylabel("Planar Center of Gravity Velocity (m/s)")
zlabel("Yaw Rate (rad/s)")

% Throttle Mapping
subplot(2,2,3)
plot(throttle, Velocity_PCoG)

% calculate mode of each track section

xlabel("Throttle")
ylabel("Planar Center of Gravity Velocity (m/s)")

% throttle-torque at steady state velocity, Moment Diagram

%% Technical Vehicle Dynamics
% suspension height, spring/damper force ratio, shock velocity, shock length,

%% Temperature Stuff
% battery temperatures, motor temperatures