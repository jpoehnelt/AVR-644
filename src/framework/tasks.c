//
// Created by Justin on 11/3/15.
//

#include "tasks.h"

#ifndef TASK_STACK_SIZE
#define TASK_STACK_SIZE 50
#endif


void shift();

void print_tasks();

Task stack[TASK_STACK_SIZE];
int stack_index = 0;

void run_tasks() {
    int i;

    for (i = 0; i < TASK_STACK_SIZE; i++) {
        if (stack[i].next != 0 && stack[i].next <= millis()) {

            // call task function
            (*stack[i].callee)(stack[i].args);

            // check if repeat is necessary
            if (stack[i].repeat != 0) {
                stack[i].next = millis() + stack[i].interval;
            } else {
                stack[i].next = 0;
            }
        }
    }
    shift();
}

void print_tasks() {
    int i;

    printf("[");
    for (i = 0; i < TASK_STACK_SIZE; i++) {
        printf("%lu", stack[i].next);

        if (i < TASK_STACK_SIZE - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

Task delayed(void (*callee), void(*args), unsigned int interval) {
    return repeated(callee, args, interval, 0);
}

Task repeated(void (*callee), void(*args), unsigned int interval, unsigned char repeat) {
    printf("Task created.\n");

    stack[stack_index++] = (Task) {
            .callee=callee,
            .next=millis() + interval,
            .interval=interval,
            .repeat=repeat,
            .args=args
    };

    return stack[stack_index - 1];
}

void shift() {
    int i, j = 0;

    for (i = 0; i < TASK_STACK_SIZE - 1; i++) {
        if (stack[i].next == 0) {

            // pull j ahead of i if necessary
            if (j <= i) {
                j = i + 1;
            }

            // move j to next task
            while (j < TASK_STACK_SIZE - 1) {
                j++;
            }

            // swap tasks
            if (stack[j].next != 0) {
                printf("Replacing Task #%d with #%d.\n", i, j);

                // swap
                Task temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;

            }
            else {
                // no more tasks to swap
                stack_index = i;
                return;
            }
        }
    }
}
