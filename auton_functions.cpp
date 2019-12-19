#include "main.h"
#include "config.hpp"
#include "auton_functions.h"
#include "cmath"
#define MOTOR_MAX_SPEED 100
const double WHEEL_RADIUS = 2.0;
const double CIRCUMFERENCE = 2*M_PI*WHEEL_RADIUS;
const double ENCODERTICKREVOLUTION = 360.0;
/**
void brakeMotors(){
  front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  front_left_wheel.move_velocity(0);
  front_right_wheel.move_velocity(0);
  back_left_wheel.move_velocity(0);
  back_right_wheel.move_velocity(0);
}
void unbrakeMotors(){
  front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

}**/

void base_PID(int distance, int max_velocity)//distance in inches
{
  const double degreeGoal = (distance/CIRCUMFERENCE) * ENCODERTICKREVOLUTION;
  const double kP = 0.6;

  double current_position = 0;
  double error = degreeGoal;
  bool goalMet = false;
  front_left_wheel.tare_position();
  front_right_wheel.tare_position();

  while (!goalMet)
  {
    current_position = (front_left_wheel.get_position() + front_right_wheel.get_position()) / 2;
    error = degreeGoal - current_position;
    double target_velocity = kP * error;

    if (target_velocity > max_velocity)
    {
      target_velocity = max_velocity;
    }
    front_left_wheel.move_velocity(target_velocity);
    front_right_wheel.move_velocity(-target_velocity);
    back_left_wheel.move_velocity(target_velocity);
    back_right_wheel.move_velocity(-target_velocity);

    if (std::abs(error) < 10)
    {
      goalMet = true;
    }
    pros::delay(8);
  }
  front_left_wheel.move_velocity(0);
  front_right_wheel.move_velocity(0);
  back_left_wheel.move_velocity(0);
  back_right_wheel.move_velocity(0);
}
void turn_PID(float targetDegree){
  front_left_wheel.tare_position();
  back_left_wheel.tare_position();
  float turn_constant = 3.7; //tune this and adjust
  int maxVelocity = 70;
  const double degreeGoal = targetDegree*turn_constant;
  bool goalMet = false;
  int targetVelocity = 0;
  int leftTarget = 0;
  int rightTarget = 0;
  double currentPosition = 0;
  double error = 0;
  double previous_error = degreeGoal;
  double kP = 0.78;
  double kI = 0.002;
  double kD = 0.001;
  double integral = 0;
  double derivative = 0;
  if(targetDegree<0){maxVelocity *= -1;}


  while(!goalMet){

      currentPosition = front_left_wheel.get_position();

    error = degreeGoal - currentPosition;
    printf("%f\r\n",currentPosition);
    if (error < 100){
      integral += error;
    }

    derivative = error - previous_error;
    previous_error = error;

    targetVelocity = kP*error + kI*integral + kD*derivative;

    if (std::abs(targetVelocity) > std::abs(maxVelocity)){
      targetVelocity = maxVelocity;
    }


      leftTarget = targetVelocity;
      rightTarget = -1*targetVelocity;

      //move left wheels with left target
      //move right wheels with right target

      front_left_wheel.move_velocity(leftTarget);
      back_left_wheel.move_velocity(leftTarget);
      front_right_wheel.move_velocity(rightTarget);
      back_right_wheel.move_velocity(rightTarget);


    if (std::abs(error) < 4){
      goalMet = true;
    }

    pros::delay(10);
  }

}
void lift_PID(int distance, int max_velocity)
{
const double degreeGoal = distance * ENCODERTICKREVOLUTION;
const double kP = 0.57;

double current_position = 0;

double error = degreeGoal;
bool goalMet = false;
double diff = 0;

lift_motor.tare_position();


while (!goalMet)
{
  current_position = lift_motor.get_position();

  error = degreeGoal - current_position;

  double target_velocity = kP * error;

  if (target_velocity > max_velocity)
  {
    target_velocity = max_velocity;
  }


  lift_motor.move_velocity(target_velocity);


  if (std::abs(error) < 10)
  {
    goalMet = true;
  }

  pros::delay(8);
  }
}

void tilter_PID(int distance, int max_velocity)
{
const double degreeGoal = distance * ENCODERTICKREVOLUTION;
const double kP =0.57;

double current_position = 0;

double error = degreeGoal;
bool goalMet = false;
double diff = 0;

tilter.tare_position();
while (!goalMet)
{
  current_position = lift_motor.get_position();

  error = degreeGoal - current_position;

  double target_velocity = kP * error;

  if (target_velocity > max_velocity)
  {
    target_velocity = max_velocity;
  }


  lift_motor.move_velocity(target_velocity);


  if (std::abs(error) < 10)
  {
    goalMet = true;
  }
  pros::delay(8);
  }

}
