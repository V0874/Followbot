#include "../motor_pwm/motor_pwm.h"

int main() {

    // set sensor pins as inputs
    setInput(&SENSOR1_DDR, SENSOR1_PIN);
    setInput(&SENSOR2_DDR, SENSOR2_PIN);
    
    // set motor 1 outputs
    setOutput(&MOTOR1_DIRECTION_DDR, MOTOR1_DIRECTION_PIN);
    setOutput(&MOTOR1_SPEED_DDR, MOTOR1_SPEED_PIN);

    // set motor 2 outputs
    setOutput(&MOTOR2_DIRECTION_DDR, MOTOR2_DIRECTION_PIN);
    setOutput(&MOTOR2_SPEED_DDR, MOTOR2_SPEED_PIN);

    // set up pwm signals
    enable_pwm(TIMER3, TIMER16BIT_FAST_PWM_8BIT, 
    TIMER16BIT_64PRESCALER, TIMER16BIT_CLEAR_OCN_MODE);
    
    while(1) {

        int right_sensor = readPin(&SENSOR1_PIN_REG, SENSOR1_PIN);
        int left_sensor = readPin(&SENSOR2_PIN_REG, SENSOR2_PIN);

            if (!right_sensor) {
            drive_motor1(TIMER3, &MOTOR1_DIRECTION_PORT, MOTOR1_DIRECTION_PIN, 35);
            } else {
                slow_motor3(TIMER3, 0);
            }

            if (!left_sensor) {
            drive_motor2(TIMER3, &MOTOR2_DIRECTION_PORT, MOTOR2_DIRECTION_PIN, 35);
            } else {
                slow_motor1(TIMER3, 0);
            }
    }
}