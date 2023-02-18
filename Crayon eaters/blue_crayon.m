clear
clc
% Connor's File

STEP_SIZE = 10;

%Parabolic function
% Updated version in Andrew's file, consider merge?
%   Added support for min motor temp at which amperage will be limited
maxMotorTemp = 99; % temp at which amps is zero
motorCoef = 1;
motorTempX = 0 : maxMotorTemp / STEP_SIZE : maxMotorTemp;
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
batteryTempX = 0 : maxBatteryTemp / STEP_SIZE : maxBatteryTemp;
batteryTempCurve = (1 - batteryCoef * ...
    (batteryTempX / maxBatteryTemp) .^ 2);