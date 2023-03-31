%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PER 2023
% Program Description 
% This program calculates various lookup tables that are related to the
% suspension of a formula style electric vehicle. In particular, the PER23
% suspension. In addition, sets various suspension parameters
%
% Input Arguments
% None
%
% Output Arguments
% None
%
% Definitions
% CCSA  - center column steering angle
%
% Lookup tables
% Damper Lookup: Damper Force = f(shock velocity, duty cycle)
% Front tire angles [FL FR] = f(CCSA)
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Startup
clearvars -except CENTER_STEER_ANGLE_MAX s l

%% Conversions
lbin2kgm = 4.44822162/0.0254; % (N*in)/(lb*m)

%% Scalar Prameters
Kz = 250*lbin2kgm; % N/m spring constant per wheel
F0z = [0 0]; % N preload per wheel
Hmax = 0.05715 + 0.0225; % m
AntiSwayR = 0.0635; % m
AntiSwayNtrlAng = pi/4; % rad
AntiSwayTrsK = 1218; % Nm/rad
ActSuspDutyCycle = 1; % none

steer_slope = 0.282; % CCSA to rack displacement slope (mm/deg)
S1 = 7E-5; % rack displacement to tire angle x^3 coefficient (deg/mm^3)
S2 = -0.0038; % rack displacement to tire angle x^2 coefficient (deg/mm^2)
S3 = 0.6535; % rack displacement to tire angle x coefficient (deg/mm)
S4 = 0.1061; % rack displacement to tire angle constant coefficient (deg)

%% Import Data
% import damper dyno data
opts = spreadsheetImportOptions("NumVariables", 4);
opts.Sheet = "0-4.3 0-4.3";
opts.DataRange = "A1:D26";
opts.VariableNames = ["VarName1", "VarName2", "VarName3", "VarName4"];
opts.VariableTypes = ["double", "double", "double", "double"];
DamperDataSample = readtable("RAW_DATA\Damper_Data_Sample.xlsx", opts, "UseExcel", false);
DamperDataSample = table2array(DamperDataSample);

%% Generate Damping Table
% extract damper velocity measurements (m/s)
sus_damper_vel = [-flipud(DamperDataSample(:,1)); DamperDataSample(2:end,3)]./1000;

% extract damper force, positive for compression (N)
sus_damper_for = [-flipud(DamperDataSample(:,2)); DamperDataSample(2:end,4)];

% calculate damping coefficient (Ns/m)
sus_damper_con = ((sus_damper_for ./ abs(sus_damper_vel)) * [1 1])';

% replace NaN damping coefficient with interpolated value
f_act_susp_cz = fillmissing(sus_damper_con,'pchip',2);

% set velocity breakpoints for damping coefficient
f_act_susp_zdot_bpt = sus_damper_vel';

% set duty cycle breakpoints (this is only applicable to active damper, for now this parameter is set to dummy value
f_act_susp_duty_bpt = [0 1];

%% Generate Front Tire Angles Table
% CCSA breakpoints 
theta_sweep = -CENTER_STEER_ANGLE_MAX:1:CENTER_STEER_ANGLE_MAX;

% rack displacement (m)
x = theta_sweep.*steer_slope;

% left tire angle (rad)
theta_left = deg2rad((S1*x.^3) - (S2*x.^2) + (S3.*x) - S4);

% right tire angle (rad)
theta_right = deg2rad((S1*x.^3) + (S2*x.^2) + (S3.*x) + S4);

% precomputation of Aeq
theta_tires = [theta_left; theta_right];
left_tires = cos(theta_tires);
right_tires = sin(theta_tires);

% left Aeq
Aeq_left = sum([s(1); l(1)] .* [left_tires(1,:); right_tires(1,:)]);

% right Aeq
Aeq_right = sum([-s(1); l(1)] .* [left_tires(2,:); right_tires(2,:)]);

%% Cleanup & Saving
clearvars -except f_act_susp_cz f_act_susp_zdot_bpt f_act_susp_duty_bpt ...
    theta_sweep theta_right theta_left Aeq_left Aeq_right steer_slope S1 ...
    S2 S3 S4 Kz F0z Hmax AntiSwayR AntiSwayNtrlAng AntiSwayTrsK ActSuspDutyCycle
save("PROCESSED_DATA\Suspension_Tables.mat")

%% Data Viewing
% scatter(f_act_susp_zdot_bpt, f_act_susp_cz(1,:))
% scatter(theta_sweep, theta_left)
% hold on
% scatter(theta_sweep, theta_right)