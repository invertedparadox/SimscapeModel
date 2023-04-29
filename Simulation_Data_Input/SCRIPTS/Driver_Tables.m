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
%% Driver Model
% Reference Generation
dx = 0.1;                   % distance between 2 track points
dIndex = 50;                % number of future track points
forward_look_straight = 5;  % number of future track points considered if current or future is a straightaway
forward_look_turn = 15;     % number of future track points considered if current and future is a turn
q_thresh = 0.3;             % threshhold between quadrants in cartesian plane
axb = -5;                   % m/s^2 Braking decceleration

% ABS System
IC = 0.15;
lambda_star = 0.15;
mu_star = 0.5;
N = 4;
lr = 35;
omega_force = 0.7.*[1 0.9 0.8 0.7]; % Forcing frequency
a = 1; % Demodulation amplitude
b = 0.02; % Modulation amplitude
phi_1 = pi/2; % Demodulation phase
phi_2 = 0; % Modulation phase
omega_lpf = 1;
omega_hpf = 0.5;
GAIN_ABS = 100;

P_Driver = 0.7;
I_Driver = 1;
MAX_I_Driver = 1;
P_Steering_Adjust = 5;

% indicies denoting each quadrant, and .5 denoting axis CCW starting from +Y axis
indicies = [3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4];

%% 
save("PROCESSED_DATA\Driver_Tables.mat")