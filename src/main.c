//
// Created by Justin on 11/3/15.
//

#include "main.h"

int main() {
    timer_init();
    uart_init();

    while(1) {
        printf("%lu \n", millis() / 1000);
        _delay_ms(500);
    }

    return 0;
}