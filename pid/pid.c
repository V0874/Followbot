#include "pid.h"

void initialize_pid(pid_t* pid){
    pid->summation = 0;
    pid->prev_error = 0;
    pid->integral = 0;
    pid->derivative = 0;
    pid->output = 0;
}

int16_t update_pid(pid_t* pid, int16_t set_point, int16_t measurement){
    
    int16_t error = set_point - measurement;

    pid->derivative = error - pid->prev_error;

    pid->derivative *= pid->kd;
    
    pid->prev_error = error;

    pid->proportional = error * pid->kp;

    pid->summation += error;

    pid->integral = pid->summation * pid->ki;

    if(pid->integral > pid->max_limit)
        pid->integral = pid->max_limit;

    if(pid->integral < pid->min_limit)
        pid->integral = pid->min_limit;   
    
    pid->output = pid->proportional + pid->integral + pid->derivative;
    return pid->output;
}