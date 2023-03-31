% Master File
STEPS = 10;

% Throttle Map
throttleX = 0:1/STEPS:1;
throttleCurve = polyval([1 0], throttleX);

% Motor Controller Map
motorControllerCurve = [25, 260; 50, 130; 75, 0];

% Motor Map
maxMotorTemp = 95;
minMotorTemp = 75;
motorTempX = minMotorTemp : (maxMotorTemp-minMotorTemp) / STEPS : maxMotorTemp;
motorTempCurve = 140 -  (motorTempX - minMotorTemp) .^ 2 .* (140) / (maxMotorTemp - minMotorTemp)^2;