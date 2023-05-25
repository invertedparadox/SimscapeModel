%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PER 2023
% Program Description 
% This program sets essential parameters for TVS
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
%% Startup
clearvars
clc;

%% TVS Parameters
% small delta parameters
dB = 0.001; % rad/s^2
dTx = 0.01; % Nm
yaw_error_limit = 0.2; % rad/s^2
low_V_SA = 0.001; % rad

% static parameters
Torque_Up_Rate_Limit = 125; % Nm/s
Torque_Down_Rate_Limit = 30000; % Nm/s
Vth = 2; % m/s
ang_acc_hystersesis = 0.1; % rad/s^2
alpha_error = 0.1;
torque_sat_const = 0.5;
default_power_dist = [0.25, 0.25, 0.25, 0.25]; % percent
min_velocity_regen = 1.4; % m/s

% tunable parameters
deadband_angle = 12;
P = 2;
I = 0;
CURRENT_BUFFER = 25; % Buffer value enforced between maxAmps and  before torque capped
TVS_Intensity = 1;
TVS_Intensity_Calibration = 1;

% Power Control Laws
STEPS = 10;

% Throttle Map
throttleX = 0:1/STEPS:1;
throttleCurve = polyval([1 0], throttleX);

% Motor Controller Map
motorControllerCurve = [25, 260; 50, 130; 75, 0];

% Motor Map
maxMotorTemp = 95;
minMotorTemp = 75;
motorTempX = minMotorTemp : (maxMotorTemp-minMotorTemp) / STEPS : maxMotorTemp;
motorTempCurve = 140 -  (motorTempX - minMotorTemp) .^ 2 .* (140) / (maxMotorTemp - minMotorTemp)^2;

%% Cleanup & Saving
save("PROCESSED_DATA\TVS_Tables.mat")