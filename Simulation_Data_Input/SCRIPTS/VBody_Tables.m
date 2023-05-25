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
clearvars -except MOTOR_ENABLE
clc;

%% Vehicle Constants
% Vehicle Body
m_unsprung = [6 6 6 6] + ([8 8 8 8] .* MOTOR_ENABLE); % kg
m_driver = 80; % kg
m_body = 180; % kg
m_all = m_body + sum(m_unsprung);

Iveh = [41.78 1.22 -41.28; 1.22 207.92 -0.32; -41.28 -0.32 209.31]; % kg*m^2

l = [0.772 0.772]; % vehicle wheelbase for PER23 [front rear] (m)
s = [0.649 0.621]; % vehicle half track width for PER23 [front rear] (m)
dZ = 0.295; % m
J_z = Iveh(3,3); % kg*m^2

Af = 1.0221; % Frontal area of vehicle with respect to aerodynamics (m^2)
Cd = 1.149; % Coefficient of drag (dimensionless)
cl = 2.11014; % Coefficient of lift (dimensionless)

phi = 45; % deg angle of firewall with resepct to horizontal

%% Cleaning up & Saving
save("PROCESSED_DATA\VBody_Tables.mat");