/*
 * File:   external_interrupts.c
 * Author: AKYakout
 *
 * Created on April 30, 2020, 1:25 PM
 */

#include "external_interrupts.h"


void external_INT_enable(ext_INT_mode mode, ext_INT_select sel){
    
    GL_INTERRUPT_DISABLE(); //critical section
    
    switch (sel){
        case INT0:
            MCUCR = (MCUCR & 0xfc) | mode;
            break;
        case INT1:
            MCUCR = (MCUCR & 0xf3) | mode;
            break;
        case INT2:
            MCUSCR = (MCUSCR & 0xbf) | mode;
            break;
       
    }
    GICR |= sel;
    GL_INTERRUPT_ENABLE();
}


void external_INT_disable(ext_INT_select sel){
    GICR &= ~(sel);
}