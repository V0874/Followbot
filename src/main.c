#include "../motor_pwm/motor_pwm.h"

int main(){

    // set sensor pins as inputs

    setInput(&DDRB, PB5);
    setInput(&DDRB, PB4);
    setInput(&DDRH, PH6);

    setOutput(&DDRB, PB7);

    // set motor 1 outputs

    setOutput(&DDRG, PG5);
    setOutput(&DDRE, PE5);

    // set motor 2 outputs

    setOutput(&DDRH, PH5);
    setOutput(&DDRE, PE3);

    // set up pwm signal

    enable_pwm_timer3();

    // read sensor input and drive motors

    while(1){

      setLow(&PORTB, PB7);

      int right = !readPin(&PINB, PB5);
      int center = !readPin(&PINB, PB4);
      int left = !readPin(&PINH, PH6);

  if (right){

    // 11 (right IR sensor) drive right motor
    setLow(&PORTH, PH5);

    setHigh(&PORTB, PB7);

  } 
  
  if (center){

    // 10 (center IR sensor) drive both motors

    // motor 1    
    setLow(&PORTG, PG5);

    // motor 2
    setLow(&PORTH, PH5);

  } 
  
  if (left){

    // 9 (left IR sensor) drive left motor
    setLow(&PORTG, PG5);

    setHigh(&PORTB, PB7);

    }

    if (right || center || left){
      setHigh(&PORTB, PB7);
    }
  } 
}