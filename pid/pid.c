#include "pid.h"

void initialize_pid(pid_t* pid){
    pid->output = 0;
}

int16_t update_pid(pid_t* pid, int16_t set_point, int16_t measurement){
    int16_t error = set_point - measurement;

    int16_t proportional = error * pid->kp;

    pid->output = proportional;
    return pid->output;
}