#include "motor_pwm.h"

int main(){

    // set sensor pins as inputs

    setInput(&PORTB, PB5);
    setInput(&PORTB, PB4);
    setInput(&PORTH, PH6);

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

   if (readPin(&PORTB, PB5)){

    // 11 (right IR sensor) drive right motor

    setLow(&PORTH, PH5);

  } else if (readPin(&PORTB, PB4)){

    // 10 (center IR sensor) drive both motors

    // motor 1    
    setLow(&PORTG, PG5);

    // motor 2
    setLow(&PORTH, PH5);

  } else if (readPin(&PORTH, PH6)){

    // 9 (left IR sensor) drive left motor

    setLow(&PORTG, PG5);

  } else {

    }
  } 
}