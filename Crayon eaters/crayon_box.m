clear
clc
% Master File

STEPS = 10;

throttleX = 0:1/STEPS:1;
throttleCurve = polyval([1 0], throttleX);

% Degrees C, Max Amps
motorControllerCurve = [25, 130;
                        50, 65;
                        75, 0];

%Parabolic function
maxMotorTemp = 100;
motorCoef = 1;
motorTempX = 0 : maxMotorTemp / STEPS : maxMotorTemp;
motorTempCurve = (1 - motorCoef * ...
    (motorTempX / maxMotorTemp) .^ 2);

%{
maxControlTemp = 100;
controlTempX = 0 : maxControlTemp / STEP_SIZE : maxControlTemp;
controlCoef = 1;
controlTempCurve = (1 - controlCoef * ...
    (controlTempX / maxControlTemp) .^ 2);
%}

maxBatteryTemp = 60;
batteryCoef = 1;
batteryTempX = 0 : maxBatteryTemp / STEPS : maxBatteryTemp;
batteryTempCurve = (1 - batteryCoef * ...
    (batteryTempX / maxBatteryTemp) .^ 2);