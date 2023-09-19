function [vel,p,q, filter,count] = fusion(velocity, position ,acceleration,angularVelocity, magField,filter, count) 
%basic
%%%%%%%%%%%%%%%%%%%FOR TESTING ONLY, PLEASE DELETE PARAMETERS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
covM = 0.4;
covV = 0.01;
covA = 610;
covG = 0.76e-5;
covP = 4; 

ratio=20;
rate=100;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%filter = insfilterAsync();
%filter.State= state;
%filter.StateCovariance = diag(1e-3*ones(28,1));

filter.predict(1./rate);
%fusion
filter.fuseaccel(acceleration,covA);
filter.fusegyro(angularVelocity,covG);

if ~mod(count,5)
    %filter.fusemag(magField,covM);
end

if ~mod(count,20)
    filter.fusegps(position,covP,velocity,covV);

end
[p,q,vel] = pose(filter);

end