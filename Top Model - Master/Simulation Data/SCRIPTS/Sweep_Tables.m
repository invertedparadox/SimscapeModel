%% Startup
clearvars -except sweep_names MAX_V MIN_V dv d0 CENTER_STEER_ANGLE_MAX
clc;

%% Parameters
sweep_name = sweep_names(1); % sweep name

%% Initialize Variables
velocity_sweep = MIN_V:dv:MAX_V;
theta_sweep = 0:d0:CENTER_STEER_ANGLE_MAX;

num1 = length(velocity_sweep);
num2 = length(theta_sweep);
num3 = 0;

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

%% Cleanup & Saving
clearvars -except ALL_SWEEP_DATA

save("..\PROCESSED_DATA\Sweep_Tables.mat")

%% Data Viewing
% scatter(velocity(:), steering_angle(:))