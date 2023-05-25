%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PER 2023 NOTE: Update tire parameters with data from web
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
clearvars -except FZ_MIN FZ_MAX
clc;

%% Scalar Prameters
WIDTH = 0.1524; % m
RIM_RADIUS = 0.1524; % m
RE = 0.223; % m
UNLOADED_RADIUS = RE + 0.002; % m
br = 1e-2; % Nm*s/rad
IYY = 0.3; % kg*m^2
VERTICAL_DAMPING = 500; % Ns/m

num_pads = 2; % count
Rm = 0.079375; % m
disk_abore = 0.0254; % m
mu_kinetic = 0.4; % none 
mu_static = 0.5; % none
brake_bias = [0.35 0.35, 0.15 0.15]; % percent
P2T = (mu_kinetic*pi*(disk_abore^2)*Rm*num_pads)./(4);

Fz = [0 204.13 427.04 668.1 895.72 1124.40 1324.40]; % tire normal force sample points (N)
cy = [0 13757.41 21278.97 26666.02 30253.47 30313.18 30313.18]; % lateral tire stiffness (N/rad)
A1 = 39.8344; % longitudinal tire stiffness x coefficient (1/rad)
A2 = 813.0780; % longitudinal tire stiffness constant coefficient (N/rad)
B1 = 0.000001287; % longitudinal tire coefficient of friction x^2 coefficient (1/N^2)
B2 = -0.002325; % longitudinal tire coefficient of friction x coefficient (1/N)
B3 = 3.797; % longitudinal tire coefficient of friction constant coefficient (none)
C1 = -0.000000002541; % lateral tire coefficient of friction x^3 coefficient (1/N^3)
C2 = 0.000005279; % lateral tire coefficient of friction x^2 coefficient (1/N^2)
C3 = -0.003943; % lateral tire coefficient of friction x coefficient (1/N)
C4 = 3.6340; % lateral tire coefficient of friction constant coefficient (none)

%% Generate Tire Tables
% create coefficient matricies for each model
p_kx = [A1 A2];
p_mx = [B1 B2 B3];
p_my = [C1 C2 C3 C4];

Fz_sweep = FZ_MIN:10:FZ_MAX; % tire normal force breakpoints (N)

% calculate tables values
kx_sweep = polyval(p_kx, Fz_sweep); % longitudinal tire stiffness (N/rad)
cy_sweep = pchip(Fz, cy, Fz_sweep); % lateral tire stiffness (N/rad)
mx_sweep = polyval(p_mx, Fz_sweep); % longitudinal coefficient of friction
my_sweep = polyval(p_my, Fz_sweep); % lateral coefficient of friction

%% Cleanup & Saving
clearvars -except Fz_sweep kx_sweep cy_sweep mx_sweep my_sweep Fz cy ...
    A1 A2 B1 B2 B3 C1 C2 C3 C4 WIDTH RIM_RADIUS RE UNLOADED_RADIUS br ...
    IYY VERTICAL_DAMPING num_pads Rm disk_abore mu_kinetic mu_static ... 
    brake_bias P2T

save("PROCESSED_DATA\Tire_Brake_Tables.mat");

%% Data Viewing
% scatter(Fz_sweep, kx_sweep)
% scatter(Fz_sweep, mx_sweep)
% scatter(Fz_sweep, my_sweep)
% 
% scatter(Fz_sweep, cy_sweep)
% hold on
% scatter(Fz, cy)