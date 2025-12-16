#include "motor_pwm.h"

void enable_pwm(timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode){
    timer16bit_timer_mode(timer, mode);
    timer16bit_set_prescaler(timer, prescaler);
    timer16bit_set_compare_output_mode(timer, output_mode);
}

void turn_left(timer16bit_t* timer, uint8_t port, uint8_t pin, uint8_t speed){
    setHigh(&port, pin); 
    timer16bit_set_output_compare_c_value(timer, speed);
}

void turn_right(timer16bit_t* timer, uint8_t port, uint8_t pin, uint8_t speed){
    setLow(&port, pin);
    timer16bit_set_output_compare_a_value(timer, speed);
}

void forward(timer16bit_t* timer, uint8_t port1, uint8_t port2, uint8_t pin1, uint8_t pin2, uint8_t speed){
    setHigh(&port1, pin1);
    setLow(&port2, pin2); 

    timer16bit_set_output_compare_c_value(timer, speed); 
    timer16bit_set_output_compare_a_value(timer, speed);
}

void stop_motor1(timer16bit_t* timer){
    timer16bit_set_output_compare_c_value(timer, 0);
}

void stop_motor3(timer16bit_t* timer){
    timer16bit_set_output_compare_a_value(timer, 0);
}