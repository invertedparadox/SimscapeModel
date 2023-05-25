%% Startup
clearvars -except sweep_names MAX_V MIN_V dv d0 CENTER_STEER_ANGLE_MAX
clc;

%% Parameters
sweep_name = sweep_names(1); % sweep name

MAX_V = 25; % maximum velocity used in simulation (m/s)
MIN_V = 18; % minimum velocity used in simulation (m/s)
dv = 1; % velocity increment used in simulation (m/s)
d0 = 5; % center column steering angle (CCSA) increment used in simulation (deg)
dt_ON = 7.5;  % time (s) that each data point is active
dt_OFF = 4.5; % time (s) between different velocities for vehicle recovery

%% Initialize Variables
velocity_sweep = MIN_V:dv:MAX_V;
theta_sweep = 0:d0:CENTER_STEER_ANGLE_MAX;

num1 = length(velocity_sweep);
num2 = length(theta_sweep);
num3 = 0;

t_total = (num1*num2*dt_ON) + (num1*dt_OFF);

velocity = ones(1, num1*(1+num2));
steering_angle = ones(1, num1*(1+num2));

%% Generate Sweep Data
for i = 1:num1
    for j = 1:num2
        velocity(((i-1)*num2)+j+num3) = velocity_sweep(i);
        steering_angle(((i-1)*num2)+j+num3) = theta_sweep(j);
    end

    velocity(((i-1)*num2)+j+num3+1) = velocity(((i-1)*num2)+j);
    steering_angle(((i-1)*num2)+j+num3+1) = 0;
    num3 = num3 + 1;
end

ALL_SWEEP_DATA.(sweep_name) = [velocity' steering_angle'];
sim_time = (dt_ON*num1*num2) + (dt_OFF*num1);

%% Cleanup & Saving
clearvars -except ALL_SWEEP_DATA MAX_V MIN_V dv d0 dt_ON dt_OFF

save("PROCESSED_DATA\Sweep_Tables.mat")

%% Data Viewing
% scatter(velocity(:), steering_angle(:))