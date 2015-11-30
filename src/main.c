//
// Created by Justin on 11/3/15.
//

#include "main.h"

void blink();

int main() {
    DDRB |= (1 << 4);
    timer_init();
    uart_init();
    spi_init();
    sei();
    _delay_ms(1000);
    printf("Done Initializing!\n");


    sd_init(DDRB, 5);


    while (1) {
        printf("Trying to init sd\n");
        uint8_t i = sd_command(0x40, {0, 0, 0, 0} ,0x95);

        if (i == 1) {
            printf("SD in Idle State\n");
        }
        else {
            printf("SD not in Idle State, i: %u\n", i);
        }

        _delay_ms(5000);

    }
}

void blink() {
    printf("Blink\n");
//    TOGGLE(LED_PORT, LED_PIN);
}