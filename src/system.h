//
// Created by Justin on 11/3/15.
//

#ifndef PROJECTS_SYSTEM_H
#define PROJECTS_SYSTEM_H


#define LED_PORT_DIR DDRB
#define LED_PORT PORTB
#define LED_PIN 0x01
#define TOGGLE(PORT, PIN) (PORT ^= PIN)


#define SPI_PORT DDRB
#define SPI_MOSI_PIN 1 << 5
#define SPI_MISO_PIN 1 << 6
#define SPI_SCK_PIN 1 << 7

#endif //PROJECTS_SYSTEM_H
