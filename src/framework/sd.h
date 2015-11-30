//
// Created by Justin on 11/29/15.
//

#ifndef PROJECTS_SD_H

#define PROJECTS_SD_H

#include "spi.h"

void sd_init(uint8_t cs_port, uint8_t cs_pin);
uint8_t sd_command(uint8_t cmd, uint16_t arg_high, uint16_t arg_low, uint8_t crc);

#endif //PROJECTS_SD_H


