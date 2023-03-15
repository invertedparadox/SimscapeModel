function [Tx_actual, bigM_flag, typed] = optimization(previous_Tx, driver_input, Vg, min_velocity_regen, lb, ub, A, b, Aeq, beq, T2F, dTx, yaw_error_limit, gr)
%% LP_calc Computation
% Developer(s):    Demetrius Gulewicz
%
% Developed for: Purdue Electric Racing
% Date:          12/25/2021
%
% Description: This function primarily computes the desired torque
%              distribution after constructing an optimization statement.
%
%
%% Pass Through Signals
% omega_m - Motor Shaft Angular Velocity [rad/s][1x4]
%
%
%% Input Only
% lb - Min Torque Request [Nm][1x4]
% ub - Max Torque Request [Nm][1x4]
% A - Power Consumed, Optimization Variable [W][1x4]
% b - Power Consumed, Driver Input [W][1x1]
% Aeq - Moment About CoG, Optimization Variable [rad/s^2][1x4]
% beq - Moment About CoG, Yaw Acceleration & Other Foces [rad/s^2][1x1]


% y - Equivalent Distances That Fy Acts From CoG [m][1x4] 
% target_ang_accel
% windup
% power_limit_battery - Max OR Min Total Battery Power Output [W][1x1]
% integrator_reset


% prev_torque - Torque Requested To Motor In Previous Time Step [Nm][4x1]
% driver_input - Proportion of total available power to use [Unitless][1x1]
% T2F - Convert Torque At The Motor Shaft to Force At The Tire [1/m][1x4]
% power_limit_battery - Max & Min Total Battery Power Output [W][1x2]
% FY - Tires Forces y Direction, Tire fixed coordinates [N][1x4]
% x - Equivalent Distances That FX Acts From CoG [m][1x4]
% y - Equivalent Distances That FY Acts From CoG [m][1x4]
% slip_limit - Max Torque Before Tire Slips [Nm][1x4]
% torque_limit_motor - Max Torque Motor Can Output [Nm][1x4]
% tau_limit_upper - Max Torque Motor Is Allowed To Change To [Nm][1x4]
% tau_limit_lower - Min Torque Motor Is Allowed To Change To [Nm][1x4]
% PID - Desired Yaw Acceleration [rad/s^2][1x1]
%
%
%% Output Only
% Tx - Torque Request To Motors [Nm][4x1]
% lb - Min Torque Request [Nm][1x4]
% ub - Max Torque Request [Nm][1x4]
% Aeq - Moment About CoG, Optimization Variable [rad/s^2][1x1]
% beq - Moment About CoG, Yaw Acceleration & Other Foces [rad/s^2][1x1]
% A - Power Consumed, Optimization Variable [W][1x1]
% b - Power Consumed, Driver Input [W][1x1]
% M_max - Max & Min Yaw Acceleration Achievable With lb & ub [rad/s^2][1x2]
% Power - Total Estimated Power Consumed by the 4 Motors
% TR - The Estimated Yaw Acceleration from the Vehicle
%
%
%% Constants
% global J_z; % Polar Moment Of Inertia [kg m^2][1x1]
% global motor_efficiency; % Motor efficiency [Unitless][1x4]
% global motor_limit_torque; % Minimum & Max Torque Request From Motor [Nm][1x2]
% global min_speed_regen; % Min Motor Shaft Speed For Regen Braking [rad/s][1x1]
% T2F - Convert Torque At The Motor Shaft to Force At The Tire [1/m][1x4]


%% Temporary
Vg = norm(Vg);


%% Detect Potential Zero Crossing, Determine Augmented lb and ub
lb_plus = lb;
ub_neg = ub;
crossing_locations = [0 0 0 0];
Tx = single([0 0 0 0]);
bigM_flag = single(0);
typed = 0;
ub_adjust = [0 0 0 0];
lb_adjust = [0 0 0 0];
signs_adjust = [0 0 0 0];

if driver_input < 0
    T2F_aug = -T2F .* gr;
    A = -A;
else
    T2F_aug = T2F .* gr;
end

for i = 1:4
    if lb_plus(i) <= 0 && ub_neg(i) >= 0
        crossing_locations(i) = i;
        
        if previous_Tx(i) >= 0
            lb_plus(i) = dTx / 2;
            ub_neg(i) = ub(i);
        elseif previous_Tx(i) < 0
            lb_plus(i) = lb(i);
            ub_neg(i) = -dTx / 2;          
        end
    end
end

signs = sign(lb_plus);

             
%% Optimization
if ~(Vg < min_velocity_regen && driver_input < 0)
        % Zero Crossing Primary Optimization
        [Tx21, Tx22, Tx23, Tx24, bigM_flag2] = call_bigM_C(T2F_aug, b, A, beq, Aeq, lb_plus, ub_neg, signs, yaw_error_limit);           
        Tx2 = double([Tx21, Tx22, Tx23, Tx24]);
        
        for i = 1:4
            if abs(Tx2(i)) <= dTx && abs(Tx2(i)) >= dTx/2 && crossing_locations(i) > 0
                if signs(i) > 0
                    lb_adjust(i) = lb(i);
                    ub_adjust(i) = -lb_plus(i);
                else
                    lb_adjust(i) = -ub_neg(i);
                    ub_adjust(i) = ub(i);  
                end
            elseif crossing_locations(i) > 0
                lb_adjust(i) = lb_plus(i);
                ub_adjust(i) = ub_neg(i);
            else
                lb_adjust(i) = lb(i);
                ub_adjust(i) = ub(i);
            end
        end
        
        signs_adjust = sign(lb_adjust);

        [Tx31, Tx32, Tx33, Tx34, bigM_flag3] = call_bigM_C(T2F_aug, b, A, beq, Aeq, lb_adjust, ub_adjust, signs_adjust, yaw_error_limit);
        Tx3 = double([Tx31, Tx32, Tx33, Tx34]);
        
        % Optimization Selection
        if bigM_flag3 == 1 || bigM_flag3 == 3
            Tx = single(Tx3);
            typed = 1;
            bigM_flag = single(bigM_flag3);
        else
            Tx = single(driver_input .* [25 25 25 25]);
            typed = 2;
            bigM_flag = single(bigM_flag3);
        end
else
    typed = 3;
    bigM_flag = single(3);
end

Tx_actual = double(Tx);

for i = 1:4
    if Tx_actual(i) > ub(i)
        Tx_actual(i) = ub(i);
    elseif Tx_actual(i) < lb(i)
        Tx_actual(i) = lb(i);
    end
end


% Torque Deadband for small input / discritization issues
for i = 1:4
    if abs(Tx_actual(i)) < 2*dTx
        Tx_actual(i) = 0;
    end
end


%% Simplified Control Scheme
% if velocity(1) > 8
%     Tx_actual = driver_input .* [0 0 25 25];
% end


end
