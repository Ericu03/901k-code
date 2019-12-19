#include "main.h"
#include "config.hpp"

void base_PID(int distance, int max_velocity);
void lift_PID(int distance, int max_velocity);
void turn_PID(float targetDegree);
void tilter_PID(int distance, int max_velocity);                                                            
