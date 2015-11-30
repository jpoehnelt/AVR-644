//
// Created by Justin on 11/29/15.
//

#include "sd.h"

uint8_t CS_PIN, CS_PORT;

void sd_init(uint8_t cs_port, uint8_t cs_pin) {
    CS_PORT = cs_port;
    CS_PIN = cs_pin;

    for (int i = 0; i < 10; i++) {
        spi(0xFF);        // send clock pulses
    }

}

uint8_t sd_command(uint8_t cmd, uint16_t arg_high, uint16_t arg_low, uint8_t crc){
    spi(0xFF);
    spi(cmd);
    spi((uint8_t) arg_high >> 8);
    spi((uint8_t) arg_high);
    spi((uint8_t) arg_low >> 8);
    spi((uint8_t) arg_low);
    spi(crc);
    spi(0xFF);

    return spi(0xFF);
}
