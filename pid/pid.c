#include "pid.h"

void initialize_pid(pid_t* pid){
    pid->kp = 40;
    pid->ki = 2;
    pid->kd = 2;

    pid->min_limit = 0;
    pid->max_limit = 255;

    pid->output = 0;
}

int16_t update_pid(pid_t* pid, int16_t set_point, int16_t measurement){
    int16_t error = set_point - measurement;

    int16_t proportional_speed = error * pid->kp;

    pid->output = proportional_speed;
    return pid->output;
}