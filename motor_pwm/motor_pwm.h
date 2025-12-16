#include "../../VFrame/vframe.h"

#define SENSOR1_DDR DDRB
#define SENSOR1_PIN PB4
#define SENSOR1_PIN_REG PINB

#define SENSOR2_DDR DDRH
#define SENSOR2_PIN PH6
#define SENSOR2_PIN_REG PINH

#define MOTOR1_DIRECTION_DDR DDRH
#define MOTOR1_DIRECTION_PORT PORTH
#define MOTOR1_DIRECTION_PIN PH5
#define MOTOR1_SPEED_DDR DDRE
#define MOTOR1_SPEED_PIN PE3

#define MOTOR2_DIRECTION_DDR DDRG
#define MOTOR2_DIRECTION_PORT PORTG
#define MOTOR2_DIRECTION_PIN PG5
#define MOTOR2_SPEED_DDR DDRE
#define MOTOR2_SPEED_PIN PE5

void enable_pwm(volatile timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode);
void drive_motor2(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed);
void drive_motor1(volatile timer16bit_t* timer, volatile uint8_t* port, uint8_t pin, uint8_t speed);
void forward(volatile timer16bit_t* timer, volatile uint8_t* motor1_port, volatile uint8_t* motor2_port, uint8_t motor1_pin, uint8_t motor2_pin, uint8_t speed);
void slow_motor1(volatile timer16bit_t* timer, uint8_t speed);
void slow_motor3(volatile timer16bit_t* timer, uint8_t speed);