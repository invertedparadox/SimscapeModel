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
%% Powertrain
Sun_gear_teeth_count = 27; % number of teeth on PER23 sun gear
Ring_gear_teeth_count = 111; % number of teeth on PER23 ring gear
Sun_Planet_gear_teeth_count = 49; % number of teeth on PER23 stage 1 planet gear
Ring_Planet_teeth_Count = 26; % number of teeth on PER23 stage 2 planet gear
PER23_gr = ((Sun_Planet_gear_teeth_count / Sun_gear_teeth_count) * (Ring_gear_teeth_count / Ring_Planet_teeth_Count)) + 1;

gr = [PER23_gr PER23_gr PER23_gr PER23_gr]; % PER23 gear ratio matrix [FL FR RL RR] (dimensionless)
gearbox_efficiency = [0.8 0.8 0.8 0.8]; % none
Motor_tau = 0.0035; % response time costant for Plettenberg Nova 15 motor (s)
mcp_Motor = 573; % Specific Heat of Plettenberg Nova 15 motor (J/K)
I_mot = 0.777559; % Polar mass moment of inertia for Plettenberg Nova 15 motor (kg/m^2)
A_mot = 0.022925; % Cooling jacket surface area for Plettenberg Nova 15 motor (m^2)

Battery_tau = 0.001; % s
Np = 5; % count
Ns = 76; % count
BattCap = Np*4; % Ah
Em = [2.8 3.375 3.65 3.9 4.15]; % V
SOC = [0 0.25 0.5 0.75 1]; % none
TEMPERATURE = [290 310]; % K
RESISTANCE = ones(length(TEMPERATURE), length(SOC)) .* 0.003; % Ohms

area_air = 0.15; % m^2
rad_air_vol = 0.01; % m^3
rad_liq_vol = 0.000157; % m^3

%% Cleaning up & Saving
save("PROCESSED_DATA\Powertrain_Tables.mat");