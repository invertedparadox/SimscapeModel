%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PER 2023 Driver
% This program defines the 2023 driver.
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
driver.control.pressure_filter = 0.05;
driver.control.brake_gain = 5;
driver.control.P_Driver = 1;
driver.control.P_Steering_Adjust = 5;
driver.control.P_High_Speed = 0.5;
driver.control.P_Straight_Adjust = 15;
driver.control.axb = -5;     % m/s^2 Braking decceleration
driver.control.dt_ON = 7.5;  % time (s) that each data point is active
driver.control.dt_OFF = 4.5; % time (s) between different velocities for vehicle recovery

% indicies denoting each quadrant, and .5 denoting axis CCW starting from +Y axis
driver.vision.indicies = [3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4];
driver.vision.dIndex = 50;                % number of future track points
driver.vision.q_thresh = 0.01;            % threshhold between quadrants in cartesian plane
driver.vision.dx = 0.1;                   % distance between 2 track points

%% Cleanup & Saving
save("PROCESSED_DATA\Driver_Tables.mat","driver")