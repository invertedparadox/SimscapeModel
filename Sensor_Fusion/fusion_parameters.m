%% To do list:
% parametrize sensor to vehicle coordinate transforms
% tune noise & covariance parameters

%% Samples Rates
fusion_t = 0.005; % sensor fusion sample period (s)
gps_hz = 1/25; % gps sample period (s)
imu_hz = 0.015; % imu sample period (s)

%% Coordinate Transformations
phi = 45; % deg

IMU_ANGLE = [0 (phi - 180) 0];
MAG_ANGLE = [180 (180 - phi) 0];

IMUNED2VNED = rotmat(quaternion(IMU_ANGLE,"eulerd","XYZ","frame"),"frame");
MAGNED2VNED = rotmat(quaternion(MAG_ANGLE,"eulerd","XYZ","frame"),"frame");

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
ACC_WALK = [ 0, 0, 0 ]; % (m/s^2)*sqrt(Hz)

GYR_ANG_WALK = [ 0, 0, 0 ]; % (rad/s)/sqrt(Hz)
GYR_BIAS_INSTABILITY = [ 0, 0, 0 ]; % (rad/s)
GYR_WALK = [ 0, 0, 0 ]; % (rad/s)*sqrt(Hz)

MAG_WHITE = [ 0, 0, 0 ]; % uT/sqrt(Hz)
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
covA = 800;
covG = 0.0001;
covM = 80;
% covP = 0.01;
covP = 34;
covV = 0.0464;

%noise measurements found in data sheet
% bmm150 bmi088 NEO-M9N
% covA=175*10^(-6)*9.81;
% covG=.004;

% covA = 0;
% covG = 0;
% covM = 0;
% covP = 34;
% covV = 0;

%% Filter Initialization
ref_location = [40.437675, -86.943750, 680]; % LLA initial position
ref_mag_field = [19.78899, -1.607, 48.9449]; % NED magnetic field

% initial state of the filter
initstate = zeros(28,1);
%orientation
initstate(1:4) = [1 0 0 0]; 
% % position
% initstate(8:10) = ref_location;
% magnetic field
initstate(23:25) = ref_mag_field;

% filter.QuaternionNoise = [1 1 1 1].*1e-6;
% filter.AngularVelocityNoise = [1 1 1].*1e-6;
% filter.PositionNoise = [1 1 1].*1e-6;
% filter.VelocityNoise = [1 1 1].*1e-6;
% filter.AccelerationNoise = [1 1 1].*1e-6;
% filter.GyroscopeBiasNoise = [1 1 1].*1e-10;
% filter.AccelerometerBiasNoise = [1 1 1].*1e-6;
% filter.GeomagneticVectorNoise = [1 1 1].*1e-6;
% filter.MagnetometerBiasNoise = [1 1 1].*1e-6;