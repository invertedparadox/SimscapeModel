%% Startup
clearvars -except A1 A2 B1 B2 B3 C1 C2 C3 C4 Fz cy FZ_MIN FZ_MAX
clc;

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
clearvars -except Fz_sweep kx_sweep cy_sweep mx_sweep my_sweep

save("PROCESSED_DATA\Tire_Tables.mat");

%% Data Viewing
% scatter(Fz_sweep, kx_sweep)
% scatter(Fz_sweep, mx_sweep)
% scatter(Fz_sweep, my_sweep)
% 
% scatter(Fz_sweep, cy_sweep)
% hold on
% scatter(Fz, cy)