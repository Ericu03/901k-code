#include "main.h"
#include "config.hpp"
#include "auton_functions.h"
//this is for skills Runs


void autonomous(){



  left_intake.move_velocity(100);
  right_intake.move_velocity(100);
  base_PID(10,60);
  pros::delay(200);
  left_intake.move_velocity(0);
  right_intake.move_velocity(0);
  turn_PID(-110);
  pros::delay(200);
  base_PID(9,50);
  pros::delay(200);
  tilter_PID(5,60);
  pros::delay(200);
  base_PID(2,20);
  pros::delay(100);
  base_PID(-5,40);
  pros::delay(200);



}
