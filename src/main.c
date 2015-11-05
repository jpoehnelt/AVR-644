//
// Created by Justin on 11/3/15.
//

#include "main.h"
void blink();

int main() {
    printf("Initializing...\n");

    timer_init();
    uart_init();

    printf("Done Initializing!\n");
    // init led pin as out
    LED_PORT_DIR = 1;

    // repeat task every 2 seconds forever
    repeated(blink, NULL, 2000, 1);

    // run tasks, sleep, run tasks, sleep, forever
    while (1) {
        run_tasks();
        sleep_mode();
        sleep_cpu();
    }

    return 0;
}

void blink() {
    TOGGLE(LED_PORT, LED_PIN);
}