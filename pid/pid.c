#include "pid.h"
#include "../motor_pwm/motor_pwm.h"

void initialize_pid(pid_t* pid){
    pid->kp = 40;
    pid->ki = 2;
    pid->kd = 2;

    pid->error = 0;
    pid->min_limit = 0;
    pid->max_limit = 255;

    pid->output = 0;
}

uint16_t update_pid(pid_t* pid, uint16_t set_point, uint16_t sensor1, uint16_t sensor2){
    uint16_t pv = sensor1 - sensor2;
    uint16_t error = set_point - pv;
    
    pid->error = error;

    uint16_t proportional_speed = error * pid->kp;

    pid->output = proportional_speed;
    return pid->output;
}