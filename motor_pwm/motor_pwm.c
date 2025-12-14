#include "motor_pwm.h"

void enable_pwm_timer3_pin3(){
    timer16bit_timer_mode(TIMER3, TIMER16BIT_FAST_PWM_8BIT);
    timer16bit_set_prescaler(TIMER3, TIMER16BIT_64PRESCALER);
    timer16bit_set_compare_output_mode(TIMER3, TIMER16BIT_CLEAR_OCN_MODE);
}

void enable_pwm_timer3_pin5(){
    timer16bit_timer_mode(TIMER3, TIMER16BIT_FAST_PWM_8BIT);
    timer16bit_set_prescaler(TIMER3, TIMER16BIT_64PRESCALER);
    timer16bit_set_compare_output_mode(TIMER3, TIMER16BIT_CLEAR_OCN_MODE);
}