#include <stdint.h>

typedef struct {
    int16_t kp;
    int16_t ki;
    int16_t kd;

    int16_t min_limit;
    int16_t max_limit;

    int16_t output;
} pid_t;

void initialize_pid(pid_t* pid);

int16_t update_pid(pid_t* pid, int16_t set_point, int16_t measurement);