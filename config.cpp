#include "config.hpp"

const int FRONT_LEFT_WHEEL = 1;
const int BACK_LEFT_WHEEL = 2;
const int FRONT_RIGHT_WHEEL = 3;
const int BACK_RIGHT_WHEEL = 4;
const int LEFT_INTAKE = 11;
const int RIGHT_INTAKE = 12;
const int LIFT_MOTOR = 7;

const int TILTER = 9;
pros::Motor front_left_wheel (FRONT_LEFT_WHEEL,pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor back_left_wheel (BACK_LEFT_WHEEL,pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor front_right_wheel (FRONT_RIGHT_WHEEL,pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor back_right_wheel (BACK_RIGHT_WHEEL,pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_intake (LEFT_INTAKE, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_intake (RIGHT_INTAKE, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift_motor (LIFT_MOTOR, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor tilter (TILTER, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Controller master(CONTROLLER_MASTER);
