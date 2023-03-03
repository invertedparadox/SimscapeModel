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
minMotorTemp = 75;
motorTempX = minMotorTemp : (maxMotorTemp-minMotorTemp) / STEPS : maxMotorTemp;
motorTempCurve = 140 -  (motorTempX - minMotorTemp) .^ 2 .* (140) / (maxMotorTemp - minMotorTemp)^2;

CURRENT_BUFFER = 5; % Buffer value enforced between maxAmps and  before torque capped