#include "../motor_pwm/motor_pwm.h"

int main(){

    // set sensor pins as inputs

    setInput(&DDRE, PE4);
    setInput(&DDRB, PB4);
    setInput(&DDRH, PH6);
    
    // set motor 1 outputs

    setOutput(&DDRG, PG5);
    setOutput(&DDRE, PE5);

    // set motor 2 outputs

    setOutput(&DDRH, PH5);
    setOutput(&DDRE, PE3);

    // set up pwm signals

    enable_pwm_timer3_pin3();
    enable_pwm_timer3_pin5();
    
    // read sensor input and drive motors

    while(1){

      int right = !readPin(&PINB, PB4);
      int left = !readPin(&PINH, PH6);
      int center = !readPin(&PINE, PE4);

  if (right){

    // 11 (right IR sensor) drive right motor
    setLow(&PORTH, PH5);
    timer16bit_set_output_compare_a_value(TIMER3, 127);

  } else {
    timer16bit_set_output_compare_a_value(TIMER3, 0);
  }
  
  if (left){

    // 9 (left IR sensor) drive left motor
    setHigh(&PORTG, PG5);
    timer16bit_set_output_compare_c_value(TIMER3, 127);

    } else {     
      timer16bit_set_output_compare_c_value(TIMER3, 0);
    }
  }
} 