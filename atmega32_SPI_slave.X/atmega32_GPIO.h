/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ATMEGA32_GPIO_H
#define	ATMEGA32_GPIO_H

    
#include "MACROS.h"
#include "Standard_types.h"
#include "uc_config.h"

#define GPIOA   ((gpio *)(0x39))
#define GPIOB   ((gpio *)(0x36))
#define GPIOC   ((gpio *)(0x33))
#define GPIOD   ((gpio *)(0x30))

typedef enum
{
    LOW,
    HIGH,
}digitalSignal;

typedef enum
{
    PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,
}gpio_pins;

typedef union
{
    vuint8 data;
    struct
    {
        vuint8 B0:1;
        vuint8 B1:1;
        vuint8 B2:1;
        vuint8 B3:1;
        vuint8 B4:1;
        vuint8 B5:1;
        vuint8 B6:1;
        vuint8 B7:1;
    }bits;
}reg8;

typedef struct
{
    reg8 pin;
    reg8 ddr;
    reg8 port;
}gpio;

typedef enum
{
    INPUTFLOAT,
    INPUTPULLUP,
    OUTPUT,
}pin_modes;


void GPIO_directionSet(gpio * G, gpio_pins pin, pin_modes mode);
digitalSignal GPIO_INPUT_Handle(gpio * G, gpio_pins pin);
void GPIO_OUTPUT_Handle(gpio * G, gpio_pins pin, digitalSignal state);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

