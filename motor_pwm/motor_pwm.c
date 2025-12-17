#include "motor_pwm.h"

void enable_pwm(volatile timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode){
    timer16bit_timer_mode(timer, mode);
    timer16bit_set_prescaler(timer, prescaler);
    timer16bit_set_compare_output_mode(timer, output_mode);
}

void drive_motor2(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setHigh(port, pin); 
    timer16bit_set_output_compare_c_value(timer, speed);
}

void drive_motor1(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed){
    setLow(port, pin);
    timer16bit_set_output_compare_a_value(timer, speed);
}

void forward(volatile timer16bit_t* timer, volatile uint8_t* motor1_port, volatile uint8_t* motor2_port, uint8_t motor1_pin, uint8_t motor2_pin, uint8_t speed){
    setHigh(motor2_port, motor2_pin);
    setLow(motor1_port, motor1_pin); 

    timer16bit_set_output_compare_c_value(timer, speed); 
    timer16bit_set_output_compare_a_value(timer, speed);
}

void slow_motor1(volatile timer16bit_t* timer, uint8_t speed){
    timer16bit_set_output_compare_c_value(timer, speed);
}
void slow_motor3(volatile timer16bit_t* timer, uint8_t speed){
    timer16bit_set_output_compare_a_value(timer, speed);
}