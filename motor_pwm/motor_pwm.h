#include "../../VFrame/vframe.h"

#define SENSOR1_PORT &DDRB
#define SENSOR1_PIN PB4
#define SENSOR1_PIN_REG &PINB

#define SENSOR2_PORT &DDRH
#define SENSOR2_PIN PH6
#define SENSOR2_PIN_REG &PINH

#define MOTOR1_DIRECTION_PORT &DDRG
#define MOTOR1_DIRECTION_PIN PG5
#define MOTOR1_SPEED_PORT &DDRE
#define MOTOR1_SPEED_PIN PE5

#define MOTOR2_DIRECTION_PORT &DDRH
#define MOTOR2_DIRECTION_PIN PH5
#define MOTOR2_SPEED_PORT &DDRE
#define MOTOR2_SPEED_PIN PE3

void enable_pwm(timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode);
void turn_left(timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed);
void turn_right(timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed);
void forward(timer16bit_t* timer, volatile uint8_t* port1, volatile uint8_t* port2, uint8_t pin1, uint8_t pin2, uint8_t speed);
void stop_motor1(timer16bit_t* timer);
void stop_motor3(timer16bit_t* timer);