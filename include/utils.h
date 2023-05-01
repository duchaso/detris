#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <errno.h>

/* Delay for msec milliseconds */
void delay(long msec);
/* Return current time in milliseconds.
Time uses CLOCK_MONOTONIC */
long get_current_time();

#endif /* UTILS_H */