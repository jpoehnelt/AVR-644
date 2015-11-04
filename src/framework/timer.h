/*
 * Author: Justin Poehnelt
 *
 * Provides millis() implementation using timer0 interrupt overflow.
 *
 * millis() will overflow in 49.7 days.
 *
 * Note: With F_CPU of 1000000, implementation lags 1 second per three minutes.
 *
 */

#ifndef PROJECTS_TIMER_H
#define PROJECTS_TIMER_H

#ifndef _AVR_INTERRUPT_H
#include <avr/interrupt.h>
#endif
#include <avr/io.h>

#ifndef _AVR_IO_H
#include <avr/io.h>
#endif

void timer_init();

long millis();

#endif //PROJECTS_TIMER_H
