#include "../motor_pwm/motor_pwm.h"
#include "../pid/pid.h"

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

    int16_t base_speed = 50;
    
    pid_t pid_controller;
    
    pid_controller.kp = 40;
    
    pid_controller.min_limit = 0;
    pid_controller.max_limit = 255;

    initialize_pid(&pid_controller);

    while(1) {

        // calculate error offset from left and right sensors
        int16_t measurement = readPin(&SENSOR1_PIN_REG, SENSOR1_PIN) - readPin(&SENSOR2_PIN_REG, SENSOR2_PIN);

        int16_t output = update_pid(&pid_controller, 0, measurement);

        // left/right motor speed is adjusted based on output and increased/decreased
        int16_t left_motor_speed = base_speed + output;
        int16_t right_motor_speed = base_speed - output;

        if(measurement < 0){
            drive_motor1(TIMER3, &MOTOR1_DIRECTION_PORT, MOTOR1_DIRECTION_PIN, left_motor_speed);
            drive_motor2(TIMER3, &MOTOR2_DIRECTION_PORT, MOTOR2_DIRECTION_PIN, right_motor_speed);
        } else if (measurement > 0) {
            drive_motor1(TIMER3, &MOTOR1_DIRECTION_PORT, MOTOR1_DIRECTION_PIN, left_motor_speed);
            drive_motor2(TIMER3, &MOTOR2_DIRECTION_PORT, MOTOR2_DIRECTION_PIN, right_motor_speed);
        } else {
            forward(TIMER3, &MOTOR1_DIRECTION_PORT, &MOTOR2_DIRECTION_PORT,
            MOTOR1_DIRECTION_PIN, MOTOR2_DIRECTION_PIN, base_speed);    
        }
    }
}