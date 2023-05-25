%% Startup
% clearvars -except rpm2radps num_datasets voltages Tx_resolution RPM_resolution V_resolution MOTOR_VOLTAGE_MAX ABS_MAX_TORQUE MOTOR_CURRENT_MAX PER23_gr RE
% clc;

%% Parameters
voltages = [340 330 320 310 300 290 280 270 260 250 240 230 220 210 190 180 170 160 150 140 130 120 110 100 90 80 70 60]; % the 28 voltages that plettenberg tested
throttles = voltages ./ max(voltages);
Tx_resolution = 26; % Number of torque breakpoints in lookup tables
RPM_resolution = 107; % Number of angular velocity breakpoints in lookup tables
V_resolution = 26; % Number of voltage breakpoints in lookup tables
num_datasets = 28; % number of sweeps for motor data from plettenberg

%% Initialize Variables
% raw data
all_voltage = []; % all raw voltage measurements (V)
all_current = []; % all raw current measurements (A)
all_rpm = [];     % all raw motor shaft angular velocity meansurements (RPM)
all_torque = [];  % all raw motor shaft torque measuremnts (Ncm)
counter = zeros(1, num_datasets);

% table breakpoints
rpm_sweep = linspace(0, 1100, RPM_resolution);  % motor shaft speed (rad/s)
torque_sweep = linspace(0, ABS_MAX_TORQUE(1), Tx_resolution);  % motor shaft torque (Nm)  
current_sweep = linspace(0, 75, Tx_resolution);  % Motor Controller Current
voltage_sweep = linspace(0, MOTOR_VOLTAGE_MAX, V_resolution); % motor voltage (V)
throttle_sweep = linspace(0, 0.99, V_resolution); % Throtttle (none)

% grid version of table breakpoints
[rpm_grid, torque_grid] = meshgrid(rpm_sweep, torque_sweep);
[~, current_grid] = meshgrid(rpm_sweep, current_sweep);
[~, voltage_grid] = meshgrid(rpm_sweep, voltage_sweep);
[~, throttle_grid] = meshgrid(rpm_sweep, throttle_sweep);

% Polynomial Models of curvy motor data
P = zeros(1, 5);
RPM_Field_Weakening = zeros(1, num_datasets);

%% Import Motor Constants
opts = spreadsheetImportOptions("NumVariables", 1);
motor_constants = zeros(5, num_datasets);
opts.DataRange = "K4:K8";
opts.VariableNames = ["Constants"];
opts.VariableTypes = ["double"];

for i = 1:1:num_datasets
    opts.Sheet = num2str(voltages(i)) + "V";
    motor_constants(:,i) = table2array(readtable("RAW_DATA\all_motor_data.xlsx", opts, "UseExcel", false));
end

no_load_rpm = (motor_constants(1,:).*rpm2radps) + 50; % rad/s
no_load_amp = (motor_constants(2,:));

%% Import Sweep Data
opts = spreadsheetImportOptions("NumVariables", 7);
motor_data = zeros(69, 7, num_datasets);
opts.DataRange = "A2:G70";
opts.VariableNames = ["VoltageV", "CurrentA", "SpeedRPM", "InputPowerW", "OutputPowerW", "TorqueNcm", "Efficiency"];
opts.VariableTypes = ["double", "double", "double", "double", "double", "double", "double"];

for i = 1:1:num_datasets
    opts.Sheet = num2str(voltages(i)) + "V";
    motor_data(:, :, i) = table2array(readtable("RAW_DATA\all_motor_data.xlsx", opts, "UseExcel", false));

    valid_data = motor_data(:, 3, i) < no_load_rpm(i)./rpm2radps;
    temp_voltage = motor_data(:, 1, i);
    temp_current = motor_data(:, 2, i);
    temp_rpm = motor_data(:, 3, i);
    temp_torque = motor_data(:, 6, i);

    all_voltage = [all_voltage; temp_voltage(valid_data)];
    all_current = [all_current; temp_current(valid_data)];
    all_rpm = [all_rpm; temp_rpm(valid_data)];
    all_torque = [all_torque; temp_torque(valid_data)];

    counter(i) = length(all_rpm);
end

%% Prepare Data for Fitting
all_rpm = all_rpm .* rpm2radps; % motor shaft angular velocity (rad/s)
all_torque = all_torque ./ 100; % motor shaft torque (Nm)
all_power_in = all_voltage .* all_current; % battery input power (W)
all_power_out = all_torque .* all_rpm; % motor output power (W)
all_efficiency = all_power_out ./ all_power_in; % motor/controller efficiency
all_throttle = all_voltage ./ max(max(all_voltage));

all_throttle_bc = [all_throttle' 0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 throttles];
all_rpm_bc = [all_rpm' 0 0 0 0 0 0 0 0 0 0 0 no_load_rpm];
all_efficiency_bc = [all_efficiency' 0 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 zeros(1,length(throttles))];
all_current_bc = [all_current' 0 0 0 0 0 0 0 0 0 0 0 no_load_amp];

%% Compute Start of Field Weakening Zone for each sweep
for i = 1:1:num_datasets
    if i == 1
        start_idx = 1;
    else
        start_idx = counter(i-1)+1;
    end

    P = polyfit(all_rpm(start_idx:counter(i)), all_current(start_idx:counter(i)),4);

    syms RPM_FW

    sol = solve(MOTOR_CURRENT_MAX == P(1)*RPM_FW^4 + P(2)*RPM_FW^3 + P(3)*RPM_FW^2 + P(4)*RPM_FW + P(5));

    if double(sol(1)) > 50
        RPM_Field_Weakening(i) = double(sol(1));
    else
        RPM_Field_Weakening(i) = double(sol(2));
    end
end

RPM_FW_Model = polyfit(voltages, RPM_Field_Weakening, 1);
RPM_FW_MAX_bkpt = polyval(RPM_FW_Model, voltage_sweep)';

%% Prepare Max Torque Lookup Table
max_torque_grid = griddata(all_rpm,all_voltage,all_torque,rpm_grid,voltage_grid);
[xData, yData, zData] = prepareSurfaceData(rpm_grid, voltage_grid, max_torque_grid);
ft = fittype('lowess');
opts = fitoptions('Method', 'LowessFit');
opts.Normalize = 'on';
opts.Span = 0.1;
[fitresult, gof] = fit([xData, yData], zData, ft, opts);

max_torque_grid = reshape(feval(fitresult,[rpm_grid(:),voltage_grid(:)]), [V_resolution, RPM_resolution]);
max_torque_grid = max(0, min(25, max_torque_grid));

%% Prepare Efficiency Lookup Table
efficiency_grid = griddata(all_rpm,all_torque,all_efficiency,rpm_grid,torque_grid);
[xData, yData, zData] = prepareSurfaceData(rpm_grid, torque_grid, efficiency_grid);
ft = fittype('loess');
opts = fitoptions('Method', 'LowessFit');
opts.Normalize = 'on';
opts.Span = 0.2;
[fitresult, gof] = fit([xData, yData], zData, ft, opts);

efficiency_grid = reshape(feval(fitresult,[rpm_grid(:),torque_grid(:)]), [Tx_resolution, RPM_resolution]);

%% Prepare Efficiency Lookup Table
efficiency_grid_A = griddata(all_rpm,all_current,all_efficiency,rpm_grid,current_grid);
[xData, yData, zData] = prepareSurfaceData( all_rpm, all_current, all_efficiency );
ft = 'biharmonicinterp';
[fitresult, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );

efficiency_grid_A = reshape(feval(fitresult,[rpm_grid(:),current_grid(:)]), [Tx_resolution, RPM_resolution]);

%% Prepare Efficiency Lookup Table
[xData, yData, zData] = prepareSurfaceData( all_throttle_bc, all_rpm_bc, all_efficiency_bc );
ft = 'linearinterp';
[fitresult, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );

efficiency_grid_BC = reshape(feval(fitresult,[throttle_grid(:), rpm_grid(:)]), [Tx_resolution, RPM_resolution]);
efficiency_grid_BC(isnan(efficiency_grid_BC))=0;

%% Prepare Current Draw Lookup Table
[xData, yData, zData] = prepareSurfaceData( all_rpm_bc, all_throttle_bc, all_current_bc );
ft = 'linearinterp';
[fitresult, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );

I_grid = reshape(feval(fitresult,[rpm_grid(:),throttle_grid(:)]), [V_resolution RPM_resolution]);
I_grid(isnan(I_grid))=0;
I_grid = I_grid .* throttle_grid;
throttle_sweep = linspace(0, 1, V_resolution); % Throtttle (none)

throttle_grid = throttle_grid .* (75 ./ 55) .* (340 ./ 315.4);

valid_currents = throttle_grid <= 1;

valid_I_grid = I_grid(valid_currents);
valid_K_grid = throttle_grid(valid_currents);
valid_W_grid = rpm_grid(valid_currents);    


%% Cleaning up & Saving
clearvars -except efficiency_grid max_torque_grid rpm_sweep torque_sweep voltage_sweep I_grid throttle_sweep efficiency_grid_A current_sweep RPM_FW_MAX_bkpt efficiency_grid_BC
save("PROCESSED_DATA\Motor_Tables.mat");

%% Data Viewing
% scatter3(all_rpm, all_torque, all_efficiency)
% scatter3(rpm_grid(:), torque_grid(:), efficiency_grid(:))
% scatter3(rpm_grid(:), voltage_grid(:), max_torque_grid_340V(:))
% scatter3(rpm_grid(:), torque_grid(:), CMD_grid(:))
% scatter3(rpm_grid(:), voltage_grid(:), I_grid(:))

% xlabel("Motor Shaft Angular Velocity (rad/s)")
% ylabel("Vmc * CMD (V)")
% zlabel("MC Current Draw (A)")

% xlabel("Motor Shaft Angular Velocity (rad/s)")
% ylabel("Vmc * CMD (V)")
% zlabel("Motor Shaft Torque (Nm)")

figure(1)
plot(RPM_FW_MAX_bkpt.*60./(2*pi),voltage_sweep./340)
hold on
plot(no_load_rpm.*60./(2*pi), voltages./340)
xlabel("Motor RPM");
ylabel("Throttle");
legend("Max Throttle Actually Used","Min Throttle Actually Used");

figure(2)
plot([0 7000 11000],[0.05,1,1]);
hold on;
plot([0 11000],[-0.05,1]);
xlabel("Motor RPM");
ylabel("Throttle");
legend("Max Throttle Actually Used","Min Throttle Actually Used");

plot(motorTempX,motorTempCurve)
hold on
plot(motorControllerCurve(:,1), motorControllerCurve(:,2))

xlabel("Temperature (degC)")
ylabel("Current Limit (A)")
legend("Motor Curve", "Motor Controller Curve")
