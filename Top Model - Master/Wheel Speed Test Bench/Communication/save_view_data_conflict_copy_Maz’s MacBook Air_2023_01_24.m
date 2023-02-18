% motor_I = s.UserData.Data(:,1)./100;
% motor_V = s.UserData.Data(:,2)./100;
% motor_W = s.UserData.Data(:,3).*0.104719755./10;
% motor_T = s.UserData.Data(:,4)./100;
% motor_K = s.UserData.Data(:,5)./100;
% magnets_W = s.UserData.Data(:,6)./10;
% ccr = s.UserData.Data(:,7);
% gears_W = s.UserData.Data(:,8)./10;

%time_array = (1:1:s.UserData.Count).*0.015;
time_array = (1:1:length(motor_V)) * 0.015;
% clear s

figure(1)
plot(time_array, motor_I)
xlabel("Time (s)")
ylabel("Current (A)")

figure(2)
plot(time_array, motor_V)
xlabel("Time (s)")
ylabel("Voltage (V)")

% figure(3)
% plot(time_array, motor_W)
% hold on
% % plot(time_array(1:400), magnets_W(1:400))
% hold on
% plot(time_array(1:400), gears_W(1:400))
% xlabel("Time (s)")
% ylabel("Speed (rad/s)")
% legend('MC Speed', 'Magnetic Speed', 'Hall Speed')

% figure(4)
% plot(time_array, motor_T)
% xlabel("Time (s)")
% ylabel("Temperature (C)")

figure(5)
plot(time_array, motor_K)
xlabel("Time (s)")
ylabel("Motor Command (%)")

% figure(7)
% plot(time_array, ccr)
% xlabel("Time (s)")
% ylabel("ccr")
