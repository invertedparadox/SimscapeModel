%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PER 2023
% Program Description 
% This program sets essential parameters for TVS power, yaw and traction
% control.
%
% Input Arguments
% None
%
% Output Arguments
% TVS Parameters
%
% Definitions
% CCSA  - center column steering angle
%
% Lookup tables
% Damper Lookup: Damper Force = f(shock velocity, duty cycle)
% Front tire angles [FL FR] = f(CCSA)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Power Control Law
tvs.power_control.dTx = 0.01; % Nm
tvs.power_control.min_velocity_regen = 1.4; % m/s

tvs.power_control.ABS_MIN_TORQUE = [0 0 0 0]; % Nm
tvs.power_control.ABS_MAX_TORQUE = [25 25 25 25]; % Nm
tvs.power_control.ABS_MAX_TRQ_CMD = dot(tvs.power_control.ABS_MAX_TORQUE, sim.top_parameters.MOTOR_ENABLE);
tvs.power_control.ABS_MIN_TRQ_CMD = dot(tvs.power_control.ABS_MIN_TORQUE, sim.top_parameters.MOTOR_ENABLE);

MOTOR_CURRENT_LIMIT = [55 55 55 55]; % A
tvs.power_control.ABS_MAX_I_FLOW = dot(MOTOR_CURRENT_LIMIT, sim.top_parameters.MOTOR_ENABLE);

dT_motor = 25; % degC
dT_motor_controller = 50; % degC

ABS_MAX_MOTOR_I = dot(sim.top_parameters.MOTOR_ENABLE,sim.range.MOTOR_CURRENT_MAX.*ones(1,4));
ABS_MAX_MOTOR_CONTROLLER_I = dot(sim.top_parameters.MOTOR_ENABLE,sim.range.MOTOR_CONTROLLER_CURRENT_MAX.*ones(1,4));

tvs.power_control.motor_controller_t_bp = [sim.range.MOTOR_CONTROLLER_TEMPERATURE_MAX-dT_motor_controller sim.range.MOTOR_CONTROLLER_TEMPERATURE_MAX];
tvs.power_control.motor_controller_I_table = [ABS_MAX_MOTOR_CONTROLLER_I 0];

tvs.power_control.motor_t_bp = [sim.range.MOTOR_TEMPERATURE_MAX-dT_motor sim.range.MOTOR_TEMPERATURE_MAX];
tvs.power_control.motor_I_table = [ABS_MAX_MOTOR_I 0];

%% Yaw Control Law
tvs.yaw_control.dy = 0.2; % rad/s^2
tvs.yaw_control.torque_sat_const = 0.5;
tvs.yaw_control.dB = 0.001; % rad/s^2

tvs.yaw_control.ang_acc_hystersesis = 0.1; % rad/s^2
tvs.yaw_control.yaw_filter = 0.1;

tvs.yaw_control.deadband_angle = 12;
tvs.yaw_control.TVS_Intensity = 1;
tvs.yaw_control.P = 20;
tvs.yaw_control.I = 0;

%% Traction Control Law
tvs.traction_control.Vth = 2; % m/s
tvs.traction_control.low_V_SA = 0.001; % rad

%% Torque Control Law
wc = 0; % rad/s
wm = 675; % rad/s
wf = 1150; % rad/s
dK = 0.025;

tvs.torque_control.omega_bp = [wc wm wf]; % rad/s
k_linear_bp = 0.05:0.05:0.95;

k_actual_1 = zeros(1,length(k_linear_bp));
k_actual_2 = ((wm/wf).*(1-k_linear_bp)) + k_linear_bp;
k_actual_3 = ones(1,length(k_linear_bp));

k_actual = [k_actual_1; k_actual_2; k_actual_3];
tvs.torque_control.k_actual = [[0; 0; 0;],[0; 0; 0;],k_actual,[1; 1; 1],[1; 1; 1]];
tvs.torque_control.k_linear_bp = [0 dK k_linear_bp 1-dK 1];


%% Cleanup & Saving
save("PROCESSED_DATA\TVS_Tables.mat","tvs")