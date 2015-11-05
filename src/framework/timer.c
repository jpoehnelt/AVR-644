#include "timer.h"

#define CYCLES_PER_MICROSECOND ( F_CPU / 1000000L )
#define PRESCALER_TICKS 64
//#define PRESCALER_TICKS 8
#define PRESCALER_BIT_PATTERN (1 << CS00 | 1 << CS01)
//#define PRESCALER_BIT_PATTERN (1 << CS01)
#define TIMER0_INTERRUPT_BIT_PATTERN (1 << TOIE0)
#define TIMER0_OVF_VALUE 256
#define MICROSECONDS_PER_TIMER0_OVF (PRESCALER_TICKS * TIMER0_OVF_VALUE / CYCLES_PER_MICROSECOND)
#define US_IN_MS 1000
#define TIMER_TASK_LIMIT 100

volatile long _millis = 0;
volatile long _micros = 0;


/*
 * Overflow Interrupt Handler
 */
ISR (TIMER0_OVF_vect) {
        // increment millis and micros with portion of interval
        _millis += MICROSECONDS_PER_TIMER0_OVF / US_IN_MS;
        _micros += MICROSECONDS_PER_TIMER0_OVF % US_IN_MS;

        // convert micros to millis as necessary
        while (_micros >= US_IN_MS) {
            _millis++;
            _micros -= US_IN_MS;
        }
}

/*
 * Initialization of timers for functionality of millis().
 */
void timer_init() {
    TCCR0B |= PRESCALER_BIT_PATTERN;
    TIMSK0 |= TIMER0_INTERRUPT_BIT_PATTERN;
    sei();
}

/*
 * Milliseconds since initialization of timer. Overflows at
 */
long millis() {
    long m;

    // could be ATOMIC_FORCEON is certain interrupts are enabled
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        m = _millis;
    }
    return m;
}