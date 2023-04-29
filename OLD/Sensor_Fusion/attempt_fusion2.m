clc 
clear all 
close all 

%accparams= accelparams('MeasurementRange',19.6,'Resolution',0.598e-3,'ConstantBias',0.49,'NoiseDensity',3920e-5,'TemperatureBias',0.294,'TemperatureScaleFactor',0.02,'AxesMisalignment',2);
%gyroparams = gyroparams('MeasurementRange',4.363,'Resolution',1.332e-04,'ConstantBias',0.349,'NoiseDensity',8.727e-4,'TemperatureBias',0.349,'TemperatureScaleFactor',0.02,'AxesMisalignment',2,'AccelerationBias',0.178e-3);

ld=load('CircularTrajectorySensorData.mat');

ld1= load('C:\Users\fullb\MATLAB Drive\Top Model - Master\Sensor_Fusion\ground_truth_data.mat');
%change sample rates for based on IMU
ld=ld1.PER22_Ground_Truth

Fs = ld.Fs; % maximum MARG rate
gpsFs = ld.gpsFs; % maximum GPS rate
ratio = Fs./gpsFs;
refloc = ld.refloc; 
imu = imuSensor('accel-gyro-mag', 'SampleRate', Fs);




imu.MagneticField=ld.magField

%imu = imuSensor('accel-gyro', 'SampleRate', Fs,'Accelerometer',accparams,'Gyroscope',gyroparams);
gps = gpsSensor('ReferenceLocation',ld.refloc);

%mag = ld.mag;



%ground truth
%trajOrient = quaternion(euler(ld.trajData.Orientation(1:999,:),"XYZ","point"),"euler","XYZ","frame");
trajOrient=ld.trajData.Orientation(1:999,:)
trajVel = ld.trajData.Velocity(1:999,:);
trajPos = ld.trajData.Position(1:999,:);
trajAcc = ld.trajData.Acceleration(1:999,:);
trajAngVel = ld.trajData.AngularVelocity(1:999,:);



%dummy1=[dummy(:)

%problems to fix x and y accelerometer to change different values
% Note seemingly fixed for now


%orangle=cos(euler(ld.trajData.Orientation,"XYZ","point"));
%veldir=[trajVel(:,1).*cosd(dummy(:,2)),-trajVel(:,1).*sind(dummy(:,2)),zeros(3529,1)];
[gpsPos,gpsVel]=gps(trajPos,trajVel);
[imuAcc,angVel,mag] =imu(trajAcc,trajAngVel,trajOrient);


accel = trajAcc;
gyro = angVel;
lla = gpsPos;
gpsvel = gpsVel;

velocity=zeros(size(accel));

fusionfilt = insfilterAsync('ReferenceLocation', refloc);

Nav = 50;
initstate = zeros(28,1);
initstate(1:4) = compact( meanrot(trajOrient(1:Nav))); 
initstate(5:7) = mean( trajAngVel(10:Nav,:), 1);
initstate(8:10) = mean( trajPos(1:Nav,:), 1);
initstate(11:13) = mean( trajVel(1:Nav,:), 1);
initstate(14:16) = mean( trajAcc(1:Nav,:), 1);
initstate(23:25) = ld.magField; 


fusionfilt.State = initstate;
%fusionfilt.QuaternionNoise = 1e-2; 
%fusionfilt.AngularVelocityNoise = 100;
%fusionfilt.AccelerationNoise = 100;
%fusionfilt.MagnetometerBiasNoise = 1e-7;
%fusionfilt.AccelerometerBiasNoise = 1e-7;
%fusionfilt.GyroscopeBiasNoise = 1e-7;

%measurements noise
Rmag = 0.1;
Rvel = 0.01;
Racc = 610;
Rgyro = 0.76e-5;
Rpos = 3.4; 

fusionfilt.StateCovariance = diag(1e-3*ones(28,1));


% %{
useErrScope = true; % Turn on the streaming error plot.
usePoseView = true; % Turn on the 3D pose viewer.
if usePoseView
    posescope = PoseViewerWithSwitches(...
        'XPositionLimits', [-300, 300], ...
        'YPositionLimits', [-300, 300 ], ...
        'ZPositionLimits', [-30, 30]);
end
f = gcf;
f.UserData.MagnetometerSampleRate=100;

f.UserData.GPSSampleRate=100

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
for ii=1:size(accel,1)
   
    fusionfilt.predict(1./Fs);
    
    % Fuse Accelerometer
 

        fusionfilt.fuseaccel(accel(ii,:), Racc);
    
    
    % Fuse Gyroscope
    

        fusionfilt.fusegyro(gyro(ii,:), Rgyro);

    
    % Fuse Magnetometer
    
    if (f.UserData.Magnetometer) && ...
        mod(ii, fix(Fs/f.UserData.MagnetometerSampleRate)) == 0

        fusionfilt.fusemag(mag(ii,:), Rmag);
    end
    %}
    % Fuse GPS
   % 
    if (f.UserData.GPS) && mod(ii, fix(Fs/f.UserData.GPSSampleRate)) == 0 
        fusionfilt.fusegps(lla(ii,:), Rpos, gpsvel(ii,:), Rvel);
    end
    
    %}
    % Plot the pose error
    %[v,p,q,fusionfilt,pizza]=fusion(gpsVel(ii,:),gpsPos(ii,:),imuAcc(ii,:),angVel(ii,:),mag(ii,:),fusionfilt,ii);
    [p,q,v] = pose(fusionfilt);
    pos(ii,:)=p;
    ang(ii,:)=q;
    velocity(ii,:)=v;
    posescope(p, q, trajPos(ii,:), trajOrient(ii));
    orientErr(ii) = rad2deg(dist(q, trajOrient(ii) ));
    posErr = p - trajPos(ii,:);
    %jerrscope(orientErr, posErr(1), posErr(2), posErr(3));
end

figure
subplot(2,2,1)
plot(1:size(velocity(:,1)),orientErr(:));





