//
// Created by Justin on 11/3/15.
//

#ifndef PROJECTS_SYSTEM_H
#define PROJECTS_SYSTEM_H


#define LED_PORT_DIR DDRB
#define LED_PORT PORTB
#define LED_PIN 0x01
#define TOGGLE(PORT, PIN) (PORT ^= PIN)

#endif //PROJECTS_SYSTEM_H
