/*
 * File:   atnega32_GPIO.c
 * Author: AKYakout
 *
 * Created on April 25, 2020, 10:05 AM
 */


#include "atmega32_GPIO.h"

void GPIO_directionSet(gpio * G, gpio_pins pin, pin_modes mode)
{
    switch (mode)
    {
        case INPUTFLOAT:
            G->ddr.bits.B2 = 0;
            CLEARBIT(G->ddr.data,pin);
            CLEARBIT(G->port.data,pin);
            break;
        case INPUTPULLUP:
            CLEARBIT(G->ddr.data,pin);
            SETBIT(G->port.data,pin);
            break;
        case OUTPUT:
            SETBIT(G->ddr.data,pin);
            break;
    }
}
digitalSignal GPIO_INPUT_Handle(gpio * G, gpio_pins pin)
{
    return ISBITSET(G->pin.data,pin);
}
void GPIO_OUTPUT_Handle(gpio * G, gpio_pins pin, digitalSignal state)
{
    if(HIGH == state)
    {
        SETBIT(G->port.data,pin);
    }
    else {
        CLEARBIT(G->port.data,pin);
    }
}
