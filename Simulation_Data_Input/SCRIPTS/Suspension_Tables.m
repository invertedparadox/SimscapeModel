%% Definitions
% CCSA  - center column steering angle

%% Startup
clearvars -except CENTER_STEER_ANGLE_MAX deg2rad steer_slope S1 S2 S3 S4
clc

%% Import Data
% import damper dyno data
opts = spreadsheetImportOptions("NumVariables", 4);
opts.Sheet = "0-4.3 0-4.3";
opts.DataRange = "A1:D26";
opts.VariableNames = ["VarName1", "VarName2", "VarName3", "VarName4"];
opts.VariableTypes = ["double", "double", "double", "double"];
DamperDataSample = readtable("..\RAW_DATA\Damper_Data_Sample.xlsx", opts, "UseExcel", false);
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
theta_left = deg2rad.*((S1*x.^3) - (S2*x.^2) + (S3.*x) - S4);

% right tire angle (rad)
theta_right = deg2rad.*((S1*x.^3) + (S2*x.^2) + (S3.*x) + S4);

%% Cleanup & Saving
% clear opts DamperDataSample sus_damper_vel sus_damper_for sus_damper_con
% clear x steer_slope S1 S2 S3 S4 CENTER_STEER_ANGLE_MAX deg2rad

clearvars -except f_act_susp_cz f_act_susp_zdot_bpt f_act_susp_duty_bpt theta_sweep theta_right theta_left

save("PROCESSED_DATA\Suspension_Tables.mat")

%% Data Viewing
% scatter(f_act_susp_zdot_bpt, f_act_susp_cz(1,:))
% scatter(theta_sweep, theta_left)
% hold on
% scatter(theta_sweep, theta_right)