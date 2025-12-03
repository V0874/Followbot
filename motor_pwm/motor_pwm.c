#include "motor_pwm.h"

void enable_pwm_timer3(){
    timer16bit_timer_mode(TIMER3, TIMER_FAST_PWM_8BIT);
    timer16bit_set_prescaler(TIMER3, TIMER_64PRESCALER);
    timer16bit_set_output_compare_a_value(TIMER3, 127);
}