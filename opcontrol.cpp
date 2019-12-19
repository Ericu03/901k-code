#include "main.h"
#include "config.hpp"
#include <math.h>

#include "auton_functions.h"

void tilter_task(void* param){
	while (true){
		if (master.get_digital(DIGITAL_X)){
			tilter_PID(5,40);
		}
		else if (master.get_digital(DIGITAL_A)){
			tilter.move_velocity(60);
		}
		else if (master.get_digital(DIGITAL_Y)){
			tilter.move_velocity(-120);
		}
		else {
    tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    tilter.move_velocity(0);
		}
		pros::delay(8);
  }
}

void lift_task(void* param){
	while (true){
		if (master.get_digital(DIGITAL_UP)){
			lift_PID(3,60);

		}
		else if (master.get_digital(DIGITAL_L1)){
			lift_motor.move_velocity(200);
		}
		else if (master.get_digital(DIGITAL_L2)){
			lift_motor.move_velocity(-200);
		}
		else{
			tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			tilter.move_velocity(0);
		}
			pros::delay(8);
	}
}


void opcontrol() {
	std::string text("tilter");
 	std::string texttwo("lift");
 	pros::Task task(lift_task,&texttwo,"");
 	pros::Task task2(tilter_task,&text,"");

	
	 while (true){
			if (master.get_analog(ANALOG_LEFT_Y)<80)
			{
				double power = 400*master.get_analog(ANALOG_RIGHT_X)/127;
				double turn = 400*master.get_analog(ANALOG_LEFT_Y)/127;
				int l = power + turn;
				int r  = power - turn;

				front_left_wheel.move_velocity(l);
				back_left_wheel.move_velocity(l);
				front_right_wheel.move_velocity(r);
				back_right_wheel.move_velocity(r);
			}
			else{
				double power = 200*master.get_analog(ANALOG_RIGHT_X)/127;
				double turn = 200*master.get_analog(ANALOG_LEFT_Y)/127;
				int l = power + turn;
				int r  = power - turn;

				front_left_wheel.move_velocity(l);
				back_left_wheel.move_velocity(l);
				front_right_wheel.move_velocity(r);
				back_right_wheel.move_velocity(r);
			}

			/** original code
			double power = 600*master.get_analog(ANALOG_LEFT_Y)/127;
				double turn = 600*master.get_analog(ANALOG_RIGHT_X)/127;
				int l = power + turn;
				int r  = power - turn;

				front_left_wheel.move_velocity(l);
				front_right_wheel.move_velocity(r);
				back_left_wheel.move_velocity(l);
				back_right_wheel.move_velocity(r);
				**/
				if (master.get_digital(DIGITAL_R1)){
				left_intake.move_velocity(220);
				right_intake.move_velocity(220);

			}
			else if (master.get_digital(DIGITAL_R2)){
				left_intake.move_velocity(-100);
				right_intake.move_velocity(-100);
			}

			else{
				left_intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
				left_intake.move_velocity(0);
				right_intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
				right_intake.move_velocity(0);

			}

/**
			if (master.get_digital(DIGITAL_X))
			{
				tilter_PID(5,40);
			}
			else{
				tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
				tilter.move_velocity(0);
			}
			if (master.get_digital(DIGITAL_LEFT))
			{
				tilter_PID(8,40);
				pros::delay(50);
				lift_PID(10,80);
			}
			else{
				lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
				lift_motor.move_velocity(0);
			}
			**/
			pros::delay(10);



			}

		}
