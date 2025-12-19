#include <stdint.h>

typedef struct {
    uint16_t kp;
    uint16_t ki;
    uint16_t kd;

    uint16_t error;

    uint16_t min_limit;
    uint16_t max_limit;

    uint16_t output;
} pid_t;

void initialize_pid(pid_t* pid);

uint16_t update_pid(pid_t* pid, uint16_t set_point, uint16_t sensor1, uint16_t sensor2);