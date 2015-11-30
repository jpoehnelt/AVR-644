//
// Created by Justin on 11/29/15.
//

#include "spi.h"

// Initialize SPI Master Device
void spi_init() {
    DDRB |= (1 << DDB5) | (1 << DDB7);  //MOSI AND SCK as OUTPUT
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);  //Enable SPI, master, FCPU/16
}

uint8_t spi(uint8_t data) {
    // Load data into the buffer
    SPDR = data;

    //Wait until transmission complete
    while (!(SPSR & (1 << SPIF)));

    // Return received data
    return SPDR;
}