#include "../../VFrame/vframe.h"

void enable_pwm(timer16bit_t* timer, uint8_t mode, uint8_t prescaler, uint8_t output_mode);
void turn_left(timer16bit_t* timer, uint8_t port, uint8_t pin, uint8_t speed);
void turn_right(timer16bit_t* timer, uint8_t port, uint8_t pin, uint8_t speed);
void forward(timer16bit_t* timer, uint8_t port1, uint8_t port2, uint8_t pin1, uint8_t pin2, uint8_t speed);
void stop_motor1(timer16bit_t* timer);
void stop_motor3(timer16bit_t* timer);