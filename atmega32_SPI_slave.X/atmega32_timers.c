/*
 * File:   atmega32_timers.c
 * Author: AKYakout
 *
 * Created on May 14, 2020, 9:31 PM
 */

#include "atmega32_timers.h"
void timer0_init(timer0_Clock_source preScale, 
        timer0_waveGenMode timerMode, 
        timer0_CompareModes cmpMode, 
        timer0_int_settings intSittings) {
         
    TIMSK &= 0xfc;
    TIMSK |= intSittings;
    TCCR0 |= preScale | timerMode | cmpMode;
}
