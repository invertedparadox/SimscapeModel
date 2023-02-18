clear
clc
% Andrew's File

STEP_SIZE = 10;

throttleX = 0:1/STEP_SIZE:1;
throttleCurve = polyval([150 0], throttleX);

% Degrees C, Max Amps for motor controller curve (first two points given)
motorControllerCurve = [25, 130;
                        50, 65;
                        75, 0];

%Parabolic function
maxMotorTemp = 99; % temp at which amps is zero
minMotorTemp = 50; % min temp to limit amps
motorCoef = 1;
motorTempX = minMotorTemp : (maxMotorTemp-minMotorTemp) / STEP_SIZE : maxMotorTemp;
% motorTempCurve = (1 - motorCoef * (motorTempX / maxMotorTemp) .^ 2);
motorTempCurve = 150 -  (motorTempX - minMotorTemp) .^ 2 .* (150) / (maxMotorTemp - minMotorTemp)^2;
%{
maxControlTemp = 100;
controlTempX = 0 : maxControlTemp / STEP_SIZE : maxControlTemp;
controlCoef = 1;
controlTempCurve = (1 - controlCoef * ...
    (controlTempX / maxControlTemp) .^ 2);
%}

maxBatteryTemp = 60;
batteryCoef = 1;
batteryTempX = 0 : maxBatteryTemp / STEP_SIZE : maxBatteryTemp;
batteryTempCurve = (1 - batteryCoef * ...
    (batteryTempX / maxBatteryTemp) .^ 2);