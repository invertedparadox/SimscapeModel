clear
clc
% Master File

STEPS = 10;

throttleX = 0:1/STEPS:1;
throttleCurve = polyval([1 0], throttleX);

% Degrees C, Max Amps
%This curve does not consider that there are two motor controllers
%Changing program to take max of both controller temps 
% and mapping to 2 times this curve
% motorControllerCurve = [25, 130;
%                         50, 65;
%                         75, 0];
motorControllerCurve = [25, 260;
                        50, 130;
                        75, 0];

%Parabolic function
maxMotorTemp = 95;
motorTempX = minMotorTemp : (maxMotorTemp-minMotorTemp) / STEPS : maxMotorTemp;
motorTempCurve = 140 -  (motorTempX - minMotorTemp) .^ 2 .* (140) / (maxMotorTemp - minMotorTemp)^2;


%{
maxControlTemp = 100;
controlTempX = 0 : maxControlTemp / STEP_SIZE : maxControlTemp;
controlCoef = 1;
controlTempCurve = (1 - controlCoef * ...
    (controlTempX / maxControlTemp) .^ 2);
%}
% 
% maxBatteryTemp = 60;
% batteryCoef = 1;
% batteryTempX = 0 : maxBatteryTemp / STEPS : maxBatteryTemp;
% batteryTempCurve = (1 - batteryCoef * ...
%     (batteryTempX / maxBatteryTemp) .^ 2);