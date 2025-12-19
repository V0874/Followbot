#include "motor_pwm.h"

void enable_pwm(volatile timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode){
    timer16bit_timer_mode(timer, mode);
    timer16bit_set_prescaler(timer, prescaler);
    timer16bit_set_compare_output_mode(timer, output_mode);
}

void forward_motor1(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setLow(port, pin);
    timer16bit_set_output_compare_a_value(timer, speed);
}

void forward_motor2(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setHigh(port, pin); 
    timer16bit_set_output_compare_c_value(timer, speed);
}

void forward(volatile timer16bit_t* timer, volatile uint8_t* motor1_port, volatile uint8_t* motor2_port, uint8_t motor1_pin, uint8_t motor2_pin, uint8_t speed){
    setLow(motor1_port, motor1_pin); 
    setHigh(motor2_port, motor2_pin);

    timer16bit_set_output_compare_c_value(timer, speed); 
    timer16bit_set_output_compare_a_value(timer, speed);
}

void backward_motor1(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setHigh(port, pin);
    timer16bit_set_output_compare_a_value(timer, speed);
}

void backward_motor2(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setLow(port, pin); 
    timer16bit_set_output_compare_c_value(timer, speed);
}

void backward(volatile timer16bit_t* timer, volatile uint8_t* motor1_port, volatile uint8_t* motor2_port, uint8_t motor1_pin, uint8_t motor2_pin, uint8_t speed){
    setHigh(motor1_port, motor1_pin);
    setLow(motor2_port, motor2_pin); 

    timer16bit_set_output_compare_c_value(timer, speed); 
    timer16bit_set_output_compare_a_value(timer, speed);
}

void change_speed_motor1(volatile timer16bit_t* timer, uint8_t speed){
    timer16bit_set_output_compare_c_value(timer, speed);
}

void change_speed_motor2(volatile timer16bit_t* timer, uint8_t speed){
    timer16bit_set_output_compare_a_value(timer, speed);
}