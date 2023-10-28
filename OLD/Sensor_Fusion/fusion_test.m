clc  
close all
%%%%%%testing fusion
%definining the parameters 
rateImu=100;
rateGps=25;
rateMag=25;
%ratio is the ratio between the IMU and a sensor 
ratioGps=rateImu/rateGps;
ratioMag=rateImu/rateMag;
assert((rem(ratioGps,1)==0),"the ratio must be a whole number");
assert((rem(ratioMag,1)==0),"the ratio must be a whole number");

t=.005;
%Ask about how case by case vs loop
%maybe using previous state as output 
%ask about constants ie. refloc, state (maybe pass them as variable)

%noise measurements found in data sheet
%bmm150 bmi088
covA=175*10^(-6)*9.81;
covG=.004;

covM=0;

covP=0;
covV=0;

Nav = 100;
initstate = zeros(28,1);


initstate(23:25) = .000005;
state=randi(10,28,1);
%%%%%%%%%%%%%%%%% done defining the parameters from the files 

%accparams= accelparams('MeasurementRange',19.6,'Resolution',0.598e-3,'ConstantBias',0.49,'NoiseDensity',3920e-5,'TemperatureBias',0.294,'TemperatureScaleFactor',0.02,'AxesMisalignment',2);
%gyroparams = gyroparams('MeasurementRange',4.363,'Resolution',1.332e-04,'ConstantBias',0.349,'NoiseDensity',8.727e-4,'TemperatureBias',0.349,'TemperatureScaleFactor',0.02,'AxesMisalignment',2,'AccelerationBias',0.178e-3);

ld=load('CircularTrajectorySensorData.mat');

Fs = ld.Fs; % maximum MARG rate
gpsFs = ld.gpsFs; % maximum GPS rate
ratio = Fs./gpsFs;
refloc = ld.refloc;
mag = ld.mag;

%ld = load('C:\Users\fullb\MATLAB Drive\Top Model - Master\Sensor_Fusion\ground_truth_data.mat');
%ld=ld.PER22_Ground_Truth
trajOrient = ld.trajData.Orientation;
trajVel = ld.trajData.Velocity;
trajPos = ld.trajData.Position;
trajAcc = ld.trajData.Acceleration;
trajAngVel = ld.trajData.AngularVelocity;

initstate(1:4) = compact( meanrot(trajOrient(1:Nav))); 
initstate(5:7) = mean( trajAngVel(10:Nav,:), 1);
initstate(8:10) = mean( trajPos(1:Nav,:), 1);
initstate(11:13) = mean( trajVel(1:Nav,:), 1);
initstate(14:16) = mean( trajAcc(1:Nav,:), 1);
initstate(23:25) = ld.magField;
initstate(20:22) = deg2rad([3.125 3.125 3.125]); 

%problems to fix x and y accelerometer to change different values
% Note seemingly fixed for now
imu = imuSensor('accel-gyro-mag', 'SampleRate', Fs);
%imu = imuSensor('accel-gyro', 'SampleRate', Fs,'Accelerometer',accparams,'Gyroscope',gyroparams);
gps = gpsSensor('ReferenceLocation',ld.refloc);
gps.VerticalPositionAccuracy=0
gps.HorizontalPositionAccuracy=0

refpos=ld.trajData.Position-ld.trajData.Position(1,:);
orangle=cos(euler(ld.trajData.Orientation,"ZYX","point"));
veldir=vecnorm(ld.trajData.Velocity,2,2).*orangle;
[gpsPos,gpsVel]=gps(refpos,trajVel);
[imuAcc,angVel] =imu(trajAcc,trajAngVel);

useErrScope = true; % Turn on the streaming error plot.
usePoseView = true; % Turn on the 3D pose viewer.
if usePoseView
    posescope = PoseViewerWithSwitches(...
        'XPositionLimits', [-30, 30], ...
        'YPositionLimits', [-30, 30 ], ...
        'ZPositionLimits', [-30, 30]);
end
f = gcf;

if useErrScope
    errscope = HelperScrollingPlotter(...
        'NumInputs', 4, ...
        'TimeSpan', 10, ...
        'SampleRate', Fs, ...
        'YLabel', {'degrees', ...
        'meters', ...
        'meters', ...
        'meters'}, ...
        'Title', {'Quaternion Distance', ...
        'Position X Error', ...
        'Position Y Error', ...
        'Position Z Error'}, ...
        'YLimits', ...
        [ -1, 30
        -2, 2
        -2 2
        -2 2]);
end
state=initstate;
for ii=1:size(trajAcc,1)
    [vel,p,q,state,pizza]=fusion(gpsVel(ii,:),gpsPos(ii,:),imuAcc(ii,:),angVel(ii,:),mag(ii,:),state,ii);
    pos1(ii,:)=p;
    ang1(ii,:)=q;
    velocity1(ii,:)=vel;
    posescope(p, q, trajPos(ii,:), trajOrient(ii));
    orientErr = rad2deg(dist(q, trajOrient(ii) ));
    posErr = p - trajPos(ii,:);
end