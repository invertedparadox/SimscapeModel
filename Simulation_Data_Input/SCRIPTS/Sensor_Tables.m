%% To do list:
% get parameters for sensors

%% Startup
clear
clc

%% Sensor Modeling Parameters
% GPS
GPS_Z_ACCURACY = 1.6; % m
GPS_XY_ACCURACY = 3; % m
GPS_V_ACCURACY = 0.1; % m/s
GPS_NOISE_FACTOR = 0.599; % none
r_GPS = randi([0 100]);

% IMU
ACC_MAX = inf; % m/s^2
ACC_RES = 0; % m/(s^2*LSB)
ACC_BIAS = [0.05 0.05 0.05]; % m/s^2 MAX: 20 mg
ACC_SKEW = [ 100, 0, 0; 0, 100, 0; 0, 0, 100 ]; % %

GYR_MAX = inf; % rad/s
GYR_RES = 0; % rad/(s*LSB)
GYR_BIAS = [0.25, 0.25, 0.25].*0.*(pi/180); % rad/s MAX: 1 deg
GYR_SKEW = [ 100, 0, 0; 0, 100, 0; 0, 0, 100 ]; % %
GYR_ACC_BIAS = [ 0, 0, 0 ]; % (rad/s)/(m/s^2)

MAG_MAX = inf; % uT
MAG_RES = 0; % uT/LSB
MAG_BIAS = [ 0, 0, 0 ]; % uT
MAG_SKEW = [ 100, 0, 0; 0, 100, 0; 0, 0, 100 ]; % %

ACC_VEL_WALK = [ 0, 0, 0 ]; % (m/s^2)/sqrt(Hz)
ACC_BIAS_INSTABILITY = [ 0, 0, 0 ]; % (m/s^2)
ACC_WALK = [ 0.01, 0.01, 0.01 ]; % (m/s^2)*sqrt(Hz)

GYR_ANG_WALK = [ 0, 0, 0 ]; % (rad/s)/sqrt(Hz)
GYR_BIAS_INSTABILITY = [ 0, 0, 0 ]; % (rad/s)
GYR_WALK = [ 0.0001, 0.0001, 0.0001 ]; % (rad/s)*sqrt(Hz)

MAG_WHITE = [ 0.1, 0.1, 0.1 ]; % uT/sqrt(Hz)
MAG_BIAS_INSTABILITY = [ 0, 0, 0 ]; % uT
MAG_WALK = [ 0, 0, 0 ]; % uT*sqrt(Hz)

ACC_T_BIAS = [ 0, 0, 0 ]; % (m/s^2)/degC MAX: 0.2 mg/K
ACC_T_SCALE = [ 0, 0, 0 ]; % %/degC

GYR_T_BIAS = [ 0, 0, 0 ]; % (rad/s)/degC MAX: 0.015deg/s*K
GYR_T_SCALE = [ 0, 0, 0 ]; % %/degC

MAG_T_BIAS = [ 0, 0, 0 ]; % uT/degC
MAG_T_SCALE = [ 0, 0, 0 ]; %/degC

r_IMU = randi([0 100]);

% Sensor Covariance
% covA = 800;
% covG = 0.0001;
% covM = 80;
% covP = 34;
% covV = 0.0464;

% covA = 4.4;
% covG = 0.0018;
% covM = 80;
% covP = 1;
% covV = 0.0464;

covA = Simulink.Parameter(4.0095);
covA.Max = 5;
covA.Min = 0.001;

covG = Simulink.Parameter(0.018);
covG.Max = 5;
covG.Min = 0.001;

covM = Simulink.Parameter(0.99);
covM.Max = 5;
covM.Min = 0.001;

covP = Simulink.Parameter(1);
covP.Max = 5;
covP.Min = 0.001;

covV = Simulink.Parameter(0.1747);
covV.Max = 5;
covV.Min = 0.001;

%% Filter Noise Parameters
QuaternionNoise = [1e-06 1e-06 1e-06 1e-06];     % none
AngularVelocityNoise = [0.005 0.005 0.005];      % (rad/s)²
PositionNoise = [1e-06 1e-06 1e-06];             % m²
VelocityNoise = [1e-06 1e-06 1e-06];             % (m/s)²
AccelerationNoise = [50 50 50];                  % (m/s²)²
GyroscopeBiasNoise = [1e-10 1e-10 1e-10];        % (rad/s)²
AccelerometerBiasNoise = [0.0001 0.0001 0.0001]; % (m/s²)²
GeomagneticVectorNoise = [1e-06 1e-06 1e-06];    % uT²
MagnetometerBiasNoise = [0.1 0.1 0.1];           % uT²

noise_state = zeros(28, 1);
noise_state(1:4) = QuaternionNoise;
noise_state(5:7) = AngularVelocityNoise;
noise_state(8:10) = PositionNoise;
noise_state(11:13) = VelocityNoise;
noise_state(14:16) = AccelerationNoise;
noise_state(17:19) = GyroscopeBiasNoise;
noise_state(20:22) = AccelerometerBiasNoise;
noise_state(23:25) = GeomagneticVectorNoise;
noise_state(26:28) = MagnetometerBiasNoise;

gyro_LP = 0.1;

%% Cleanup & Saving
save("PROCESSED_DATA\Sensor_Tables.mat")