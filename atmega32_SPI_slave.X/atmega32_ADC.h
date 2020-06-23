/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

 
#ifndef ATMEGA32_ADC_H
#define	ATMEGA32_ADC_H

#include "external_interrupts.h"
#include "atmega32_GPIO.h"


#define     ADMUX       (*(vuint8 *)0x27)
#define     ADCSRA      (*(vuint8 *)0x26)
#define     ADCH        (*(vuint8 *)0x25)
#define     ADCL        (*(vuint8 *)0x24)
#define     SFIOR       (*(vuint8 *)0x50)


typedef enum{
    AREF_REF_volt = 0x00,
    AVCC_REF_volt = 0x40,
    Internal_2p5_REF_volt = 0xc0,        
}ADC_REF_volt_SEL;

typedef enum{
    singleConv = 0x0000,
    freeRunningMode = 0x0100,
    analogCoparator = 0x0120,
    externalInterruptRequest0 = 0x0140,
    timer0CompareMatch = 0x0160,
    timer0Overflow = 0x0180,
    timer1CompareMatch = 0x01a0,
    timer1Overflow = 0x01c0,
    timer1CaptureEvent = 0x01e0,
}ADC_trigger_source;

typedef enum{
    devideBy2 = 0x01,
    devideBy4,
    devideBy8,
    devideBy16,
    devideBy32,
    devideBy64,
    devideBy128,
}ADC_prescale_factor;

typedef enum {
    ADC0,ADC1,ADC2,ADC3,
    ADC4,ADC5,ADC6,ADC7,
            D_PADC0_NADC0_10x,D_PADC1_NADC0_10x,
            D_PADC0_NADC0_200x,D_PADC1_NADC0_200x,
            
}ADC_Channel;

typedef enum {
    LIFT_ADJUST = 0x00,
    RIGHT_ADJUST = 0x20,
}ADC_Adjust_result;

typedef enum {
    ADC_INT_DISABLE = 0x00,
    ADC_INT_ENABLE = 0x08,
}ADC_INT_state;

typedef enum {
    ADC_8BIT,
    ADC_10BIT,
}ADC_RES;

void ADC_init(ADC_REF_volt_SEL refSel, ADC_prescale_factor preS, ADC_trigger_source tSource, ADC_INT_state intState);
uint16 ADC_singleRead(ADC_Channel ch, ADC_RES Res);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

