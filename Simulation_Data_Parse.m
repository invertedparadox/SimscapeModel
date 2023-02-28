%% Startup
% clearvars -except out

%% Extract Bus Data
TV_OUTPUT = out.TV_Output;
MCPL_OUTPUT = out.MCPL_Output;
Reference_Signals = out.Navigation_Reference;
Reference_Generator = out.Reference_Generator;
Digital_Signals = out.Digital_Signals;
time = Digital_Signals.Navigation_Sensors.gyro.Time;
time_15 = TV_OUTPUT.ub.Time;

%% Vehicle Dynamics
yaw_rates = Reference_Signals.Chassis_AngularVelocity.Data(:,3);
ref_yaw_rates = TV_OUTPUT.ref_yaw.Data;

X = Reference_Signals.Chassis_Position.X.Data(:);
Y = Reference_Signals.Chassis_Position.Y.Data(:);

X_ref = Reference_Generator.x_ref.Data;
Y_ref = Reference_Generator.y_ref.Data;

omega = squeeze(Digital_Signals.Corner_Dynamics_Sensors.omega.Data)';
Fz = Digital_Signals.Corner_Dynamics_Sensors.FZ.Data;
steer = Digital_Signals.Corner_Dynamics_Sensors.theta.Data;

%% TVS
flag = TV_OUTPUT.bigM_flag.Data;

torque_out = squeeze(MCPL_OUTPUT.T.Data)';
ub_torque = TV_OUTPUT.ub.Data;
lb_torque = TV_OUTPUT.lb.Data;

ang_acc = TV_OUTPUT.beq.Data;
pre_limit_ang_acc = out.pre_limit_ang_acc.Data;
max_ang_acc = TV_OUTPUT.max_ang_acc.Data;
min_ang_acc = TV_OUTPUT.min_ang_acc.Data;

batt_I = Digital_Signals.Power_Sensors.battery_I.Data;
batt_V = Digital_Signals.Power_Sensors.battery_V.Data;
driver_power_req = TV_OUTPUT.b.Data;

%% Error Terms
yaw_error = out.yaw_error.Data;
dis_error = Reference_Generator.d_error.Data;
rad_error = Reference_Generator.r_error.Data;
psi_error = Reference_Generator.psi_error.Data;
ang_acc_error = ang_acc;

%% Plotting Vehicle Dynamics
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

xlabel("time (s)")
ylabel("Steering Angle (deg)")
legend("Actual","TOY Steering Angle")

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

% rear torque
subplot(2,2,1)
plot(time_15, torque_out(:,3))
hold on
plot(time_15, torque_out(:,4))
hold on
plot(time_15, lb_torque(:,3))
hold on
plot(time_15, lb_torque(:,4))
hold on
plot(time_15, ub_torque(:,3))
hold on
plot(time_15, ub_torque(:,4))

xlabel("time (s)")
ylabel("Torque (Nm)")
legend("RL Torque","RR Torque","RL UB","RR UB","RL LB","RR LB")

% control signal
subplot(2,2,2)
plot(time_15,ang_acc)
hold on
plot(time_15, pre_limit_ang_acc)
hold on
plot(time_15, max_ang_acc)
hold on
plot(time_15, min_ang_acc)

xlabel("time (s)")
ylabel("Angular Acceleration (rad/s^2)")
legend("Actual","Pre Limit", "MAX", "MIN")

% power consumption
subplot(2,2,3)
plot(time_15, driver_power_req)
hold on
plot(time_15, batt_V.*batt_I)

xlabel("time (s)")
ylabel("Power (W)")
legend("Reference","Actual")

% yaw rate
subplot(2,2,4)
plot(time_15, ref_yaw_rates)
hold on
plot(time, yaw_rates)

xlabel("time (s)")
ylabel("Yaw Rate (rad/s)")
legend("Reference","Actual")

%% Plotting Simulation Errors
figure(3)

% distance error
subplot(2,2,1)
plot(time_15, dis_error)

xlabel("time (s)")
ylabel("Distance (m)")

% yaw error
subplot(2,2,2)
plot(time_15, yaw_error)

xlabel("time (s)")
ylabel("Yaw Rate (rad/s)")

% orientation error
subplot(2,2,3)
plot(time_15, psi_error)

xlabel("time (s)")
ylabel("Angle (rad)")

% turning radius error
subplot(2,2,4)
plot(time_15, rad_error)

xlabel("time (s)")
ylabel("Turning Radius (m)")