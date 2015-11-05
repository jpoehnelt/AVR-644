//
// Created by Justin on 11/3/15.
//

#ifndef FRAMEWORK_TASKS_H
#define FRAMEWORK_TASKS_H

#ifndef FRAMEWORK_TIMER_H
#include "timer.h"
#endif

#ifndef _AVR_SLEEP_H
#include <avr/sleep.h>
#endif

typedef struct Task {
    unsigned int interval; // in milliseconds
    unsigned char repeat;
    unsigned long next;
    void (*callee) ();
    void *args;
} Task;

Task delayed(void (*callee), void(*args), unsigned int interval);

Task repeated(void (*callee), void(*args), unsigned int interval, unsigned char repeat);

void run_tasks();
void print_tasks();

#endif //FRAMEWORK_TASKS_H
