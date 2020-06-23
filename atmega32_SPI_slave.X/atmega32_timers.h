/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

 
#ifndef ATMEGA32_TIMERS_H
#define	ATMEGA32_TIMERS_H

#include "atmega32_ADC.h"

#define     TIMSK         (*(vuint8 *)0x59)
#define     TIFR          (*(vuint8 *)0x58)
//timer0 registers
#define     TCCR0         (*(vuint8 *)0x53)
#define     TCNT0         (*(vuint8 *)0x52)
#define     OCR0          (*(vuint8 *)0x5c)
//timer1 registers
#define     TCCR1A        (*(vuint8 *)0x4f)
#define     TCCR1B        (*(vuint8 *)0x4e)
#define     TCNT1H        (*(vuint8 *)0x4d)
#define     TCNT1L        (*(vuint8 *)0x4c)
#define     OCR1AH        (*(vuint8 *)0x4b)
#define     OCR1AL        (*(vuint8 *)0x4a)
#define     OCR1BH        (*(vuint8 *)0x49)
#define     OCR1BL        (*(vuint8 *)0x48)
#define     ICR1H         (*(vuint8 *)0x47)
#define     ICR1L         (*(vuint8 *)0x46)
//timer2 registers
#define     TCCR2         (*(vuint8 *)0x45)
#define     TCNT2         (*(vuint8 *)0x44)
#define     OCR2          (*(vuint8 *)0x43)

typedef enum {
    T0_normal = 0x00,
    T0_PWMPHC = 0x40,
    T0_CTCMODE = 0x08,
    T0_PWMFAST = 0x48,
}timer0_waveGenMode;


typedef enum {
    T0_OC0DISCONNECT = 0x00,
    T0_NONPWM_TOGGLEOC0 = 0x10,
    T0_NONPWM_CLEAROC0 = 0x20,
    T0_NONPWM_SETOC0 = 0x30,
            
    T0_PWMFAST_NONINVERT = 0x20,
    T0_PWMFAST_INVERT = 0x30,
            
    T0_PWMPHC_NONINVERT = 0x20,
    T0_PWMPHC_INVERT = 0x30,
}timer0_CompareModes;

typedef enum {
    T0_DISABLE = 0x00,
	T0_FCPU,
	T0_FCPU_BY_8,
	T0_FCPU_BY_64,
	T0_FCPU_BY_256,
	T0_FCPU_BY_1024,
	T0_EXCLK_FALLING,
	T0_EXCLK_RISING,
}timer0_Clock_source;

typedef enum {
    T0_int_DISABLE = 0x00,
            T0_OVF_ENABLE,
            T0_OCF_ENABLE,
            T0_OVF_OCF_ENABLE,
            
}timer0_int_settings;

void timer0_init(timer0_Clock_source preScale, 
        timer0_waveGenMode timerMode, 
        timer0_CompareModes cmpMode, 
        timer0_int_settings intSittings);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

