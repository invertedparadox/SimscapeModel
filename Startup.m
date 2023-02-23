%% Startup
% clear
% clc

%% Load Table Data
%sscfluids_ev_battery_cooling
load("Simulation_Data_Input\PROCESSED_DATA\Track_Tables.mat")
load("Simulation_Data_Input\PROCESSED_DATA\Sweep_Tables.mat")
load("Simulation_Data_Input\PROCESSED_DATA\Tire_Tables.mat");
load("Simulation_Data_Input\PROCESSED_DATA\Suspension_Tables.mat");
load("Simulation_Data_Input\PROCESSED_DATA\Yaw_Tables.mat");
load("Simulation_Data_Input\PROCESSED_DATA\Motor_Tables.mat");
load("Simulation_Data_Input\PROCESSED_DATA\VehFdbk.mat");
load("Simulation_Data_Input\PROCESSED_DATA\Sensor_Tables.mat");

%% Generate Extra Data
VehFdbk_Void = Simulink.Bus.createObject(VehFdbk_Struct);
VehFdbk = evalin('base', VehFdbk_Void.busName);

event_names = ["acceleration", "skidpad", "austria_endurance", "l_square", "r_square", "short_oc", "grand_prix", "track_Left", "track_Right", "long_straight"];
selected_track = ALL_TRACK_DATA.(event_names(7));

sweep_names = ["ccw_steering"];
selected_sweep = ALL_SWEEP_DATA.(sweep_names(1));

%% Simulation Top Parameters
YAW_ENABLE = 1;  % Enable yaw rate sweeping when set to 0
TVS_ENABLE = 1;  % Enable TVS when set to 1
traction_enable = 1; % Enable variable objective function coefficients
motor_enable = [0 0 1 1]; % Enable motors (bool)
t = 0.015; % step size of all discrete systems (s)
veh_vel = 7; % simulation target PCoGV (m/s)

%% Simulation Strange Parameters
LONGVL = 16.7; % m/s
FNOMIN = 850; % N
NOMPRES = 82737; % Pa
VXLOW = 0.1; % m/s
xdot_tol = 0.1; % m/s

beta_w = [0 0.01:0.01:0.3]; % rad
Cs = [0 0.01:0.01:0.3]; % none
Cym = [0 1e-6:0.01:0.3]; % none
cpm = .1; % none

%% TVS MISC Parameters
dB = 0.0001; % rad/s^2
dTx = 0.01; % Nm
yaw_error_limit = 0.2; % rad/s^2
Torque_Up_Rate_Limit = 125; % Nm/s
Torque_Down_Rate_Limit = 300; % Nm/s
low_V_SA = 0.001; % rad
Vth = 2; % m/s
ref_yaw_hysteresis = 0.1; % rad/s
ref_yaw_state = 0; % bool
ang_acc_drop_limit = 10; % rad/s^2
ang_acc_hystersesis = 0.1; % rad/s^2
TOY_correction_factor = 0.1; % increase/decrease in yaw rate to bring reference yaw rate closer to TOY (time optimal yaw rate)
yaw_bias = 0.01;
alpha_error = 0.1;

torque_sat_const = 0.5;
default_power_dist = [0.25, 0.25, 0.25, 0.25]; % percent

battery_current_hysteresis = 2; % A
battery_power_hysteresis = 500; % W
torque_down_constant = 0.75; % A
power_state = 0; % bool
max_K = 4095; % none

TRQ_CMD_PL_SEARCH_RANGE = 0:0.001:1;

%% Data Processing Misc Parameters
voltages = [340 330 320 310 300 290 280 270 260 250 240 230 220 210 190 180 170 160 150 140 130 120 110 100 90 80 70 60]; % the 28 voltages that plettenberg tested at
Tx_resolution = 26; % Number of torque breakpoints in lookup tables
RPM_resolution = 107; % Number of angular velocity breakpoints in lookup tables
V_resolution = 26; % Number of voltage breakpoints in lookup tables
num_datasets = 28; % number of sweeps for motor data from plettenberg

%% Signal Max/Min Clamping
% navigation sensors
VELOCITY_MAX = 30; % m/s
YAW_MAX = 2.5; % rad/s
ACCELERATION_MAX = 30; % m/s^2
ORIENTATION_MAX = 360; % deg
MAG_MAX = 200; % uT

% power sensors
BATTERY_VOLTAGE_MAX = 340; % V
BATTERY_VOLTAGE_MIN = 60; % V
BATTERY_CURRENT_MAX = 75; % A
BATTERY_CURRENT_MIN = 0; % A
MOTOR_VOLTAGE_MAX = 340; % V
MOTOR_VOLTAGE_MIN = 90; % V
DCL_MAX = 50; % A
DCL_MIN = 0; % A

% temperature sensors
MOTOR_TEMPERATURE_MAX = 400; % K
MOTOR_TEMPERATURE_MIN = 0; % K
BATTERY_TEMPERATURE_MAX = 400; % K
BATTERY_TEMPERATURE_MIN = 0; % K

% corner dynamics sensors
CENTER_STEER_ANGLE_MAX = 130; % deg
OMEGA_MAX = 150; % rad/s
OMEGA_MIN = 0; % rad/s
SHOCK_LENGTH_MAX = 0.25; % m
SHOCK_LENGTH_MIN = 0; % m
FZ_MAX = 1200; % N
FZ_MIN = 200; % N

% tvs saturation
ABS_MIN_TORQUE = [0 0 0 0]; % Nm
ABS_MAX_TORQUE = [25 25 25 25]; % Nm
ABS_MAX_TRQ_CMD = dot(ABS_MAX_TORQUE, motor_enable);
ABS_MIN_TRQ_CMD = sum(motor_enable) * 0.5 * dTx;
MAX_CURRENT = DCL_MAX; % A
MIN_CURRENT = 0.1; % A
MAX_DRIVER_INPUT = 1; % unitless
MAX_MOTOR_CURRENT = 70; % A

% subsystem design saturation
TIRE_ANGLE_MAX = 0.5; % rad
VELOCITY_MAX_XY = norm(VELOCITY_MAX.*[1 1]); % m/s
REF_YAW_MAX = 1.25; % rad/s

%% True Constants
deg2rad = 0.01745329; % multiply to convert from deg to rad (rad/deg)
rpm2radps = 0.104719755; % multipe to convert RPM to rad/s (rad/RPM*s)
lbin2kgm = 4.44822162/0.0254; % (N*in)/(lb*m)
g = 9.81; % m/s^2
rho = 1.225; % kg/m^3
Tair = 300; % K
Pair = 101325; % Pa
min_velocity_regen = 1.4; % m/s

%% Vehicle Constants
% Vehicle Body
m = 300 + sum([10 10 10 10] .* motor_enable); % kg

%	Izz = 41782359388.78          Izx = 1218939069.69       Izy = -41283226162.43	
%	Ixz = 1218939069.69            Ixx = 207923119475.86   Ixy = -323722590.99 
% 	Iyz = -41283226162.43        Iyx = -323722590.9          Iyy = 209310186667.15
% Iveh = [242581 -12979 -144891; -12979 1520924 -2283; -144891 -2283  1602598]./1000;

Iveh = [41.78 1.22 -41.28; 1.22 207.92 -0.32; -41.28 -0.32 209.31]; % kg*m^2

l = [0.772 0.772]; % vehicle wheelbase for PER23 [front rear] (m)
s = [0.649 0.621]; % vehicle half track width for PER23 [front rear] (m)
dZ = 0.295; % m

Af = 1.0221; % Frontal area of vehicle with respect to aerodynamics (m^2)
Cd = 1.149; % Coefficient of drag (dimensionless)
cl = 2.11014; % Coefficient of lift (dimensionless)

J_z = 75; % kg*m^2

% Powertrain
Sun_gear_teeth_count = 27; % number of teeth on PER23 sun gear
Ring_gear_teeth_count = 111; % number of teeth on PER23 ring gear
Sun_Planet_gear_teeth_count = 49; % number of teeth on PER23 stage 1 planet gear
Ring_Planet_teeth_Count = 26; % number of teeth on PER23 stage 2 planet gear
PER23_gr = ((Sun_Planet_gear_teeth_count / Sun_gear_teeth_count) * (Ring_gear_teeth_count / Ring_Planet_teeth_Count)) + 1;

gr = [6.63043 6.63043 PER23_gr PER23_gr]; % PER23 gear ratio matrix [FL FR RL RR] (dimensionless)
motor_efficiency = [0.85 0.85 0.85 0.85]; % none
gearbox_efficiency = [0.8 0.8 0.8 0.8]; % none
Motor_tau = 0.0035; % response time costant for Plettenberg Nova 15 motor (s)
mcp_Motor = 573; % Specific Heat of Plettenberg Nova 15 motor (J/K)
I_mot = 0.777559; % Polar mass moment of inertia for Plettenberg Nova 15 motor (kg/m^2)
A_mot = 0.022925; % Cooling jacket surface area for Plettenberg Nova 15 motor (m^2)

BattCap = 16; % Ah
Battery_tau = 0.001; % s
Np = 4; % count
Ns = 80; % count
Em = [2.8 3.375 3.65 3.9 4.15]; % V
SOC = [0 0.25 0.5 0.75 1]; % none
TEMPERATURE = [290 310]; % K
RESISTANCE = ones(length(TEMPERATURE), length(SOC)) .* 0.03; % Ohms

area_air = 0.15; % m^2
rad_air_vol = 0.01; % m^3
rad_liq_vol = 0.000157; % m^3

% Suspension
Kz = 250*lbin2kgm; % N/m spring constant per wheel
F0z = [0 0]; % N preload per wheel
Hmax = 0.05715 + 0.0225; % m
AntiSwayR = 0.0635; % m
AntiSwayNtrlAng = pi/4; % rad
AntiSwayTrsK = 1218; % Nm/rad
ActSuspDutyCycle = 1; % none

steer_slope = 0.282; % CCSA to rack displacement slope (mm/deg)
S1 = 7E-5; % rack displacement to tire angle x^3 coefficient (deg/mm^3)
S2 = -0.0038; % rack displacement to tire angle x^2 coefficient (deg/mm^2)
S3 = 0.6535; % rack displacement to tire angle x coefficient (deg/mm)
S4 = 0.1061; % rack displacement to tire angle constant coefficient (deg)

% Tire & Brake
m_unsprung = [6 6 6 6] + ([10 10 10 10] .* motor_enable); % kg
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
brake_bias = [0.65 0.65 0.35 0.35]; % percent
di2bp = 20; % MPa
brakecoeff = [61.33 61.33 40.54 40.54]; % Nm/MPa

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

%% TVS Tunable Parameters
deadband_angle = Simulink.Parameter(12);
deadband_angle.Complexity = 'real';
deadband_angle.CoderInfo.StorageClass = 'Model default';
deadband_angle.DataType = 'auto';

Kv = Simulink.Parameter(3);
Kv.Complexity = 'real';
Kv.CoderInfo.StorageClass = 'Model default';
Kv.DataType = 'auto';

Ku = Simulink.Parameter(0);
Ku.Complexity = 'real';
Ku.CoderInfo.StorageClass = 'Model default';
Ku.DataType = 'auto';

P = Simulink.Parameter(1);
P.Complexity = 'real';
P.CoderInfo.StorageClass = 'Model default';
P.DataType = 'auto';

I = Simulink.Parameter(0);
I.Complexity = 'real';
I.CoderInfo.StorageClass = 'Model default';
I.DataType = 'auto';

V_target = [0 3 6 9 12 15 18 21 25 31];
max_yaw_field = [0.67 0.67 0.67 0.83 0.57 0.62 0.377 0.4245 0.425 0.425];

%% Simulation Initial Conditions
% navigation sensors
vel_IC = 0; % m/s
pos_IC = 0; % m
acc_IC = 0; % m/s^2
ang_IC = 0; % rad
ang_vel_IC = 0; % rad/s

GPS_pos_IC = [40.437675; -86.943750; 680]; % deg deg m

% power sensors
battery_voltage_IC = 336; % V
battery_current_IC = 0; % A
motor_voltage_IC = 336; % V
motor_current_IC = 0; % A
dcl_IC = 150; % A
ccl_IC = 0;

% temperature sensors
motor_T_IC = 300; % K
motor_FT_IC = 300; % K
battery_T_IC = 300; % K
battery_FT_IC = 300; % K

% corner dynamics sensors
omega_IC = 0; % rad/s
theta_IC = 0; % deg
shock_length_IC = 0.1; % m
Fz_IC = m*g/4; % N

% tvs initial conditions
Tx_I = 0; % Nm
windup_I = 0; % bool
motor_efficiency_IC = 0.31; % none

% vehicle initial conditions
BattCap_I = 16;
zdot_tires_IC = 0; % m/s
z_tire_IC = 0; % m

%% Driver Model
% Reference Generation
dx = 0.1;                   % distance between 2 track points
dIndex = 50;                % number of future track points
forward_look_straight = 5;  % number of future track points considered if current or future is a straightaway
forward_look_turn = 15;     % number of future track points considered if current and future is a turn
q_thresh = 0.05;            % threshhold between quadrants in cartesian plane

% indicies denoting each quadrant, and .5 denoting axis CCW starting from +Y axis
indicies = [3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4 0.5 1 1.5 2 2.5 3 3.5 4];

%% PCoGV & CCSA Sweep Simulation
MAX_V = 18; % maximum velocity used in simulation (m/s)
MIN_V = 5; % minimum velocity used in simulation (m/s)
dv = 1; % velocity increment used in simulation (m/s)
d0 = 5; % center column steering angle (CCSA) increment used in simulation (deg)
dt_ON = 7.5;  % time (s) that each data point is active
dt_OFF = 4.5; % time (s) between different velocities for vehicle recovery