#include "utils.h"

void delay(long msec) 
{
    struct timespec ts;
    
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}

long get_current_time()
{
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);
    return spec.tv_sec * 1000 + spec.tv_nsec / 1e6;
}