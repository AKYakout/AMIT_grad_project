/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

  
#ifndef EXTERNAL_INTERRUPTS_H
#define	EXTERNAL_INTERRUPTS_H

#include "atmega32_GPIO.h"

#define GL_INTERRUPT_ENABLE()     (SETBIT(SREG,7))
#define GL_INTERRUPT_DISABLE()     (CLEARBIT(SREG,7))


#define SREG        (*(vuint8 *)0x5f)
#define MCUCR       (*(vuint8 *)0x55)
#define MCUSCR      (*(vuint8 *)0x54)
#define GICR        (*(vuint8 *)0x5b)
#define GIFR        (*(vuint8 *)0x5a)


typedef enum{
    INT0_lowLevel = 0x00,
    INT0_Toggle = 0x01,
    INT0_Falling = 0x02,
    INT0_Rising = 0x03,
    INT1_lowLevel = 0x00,
    INT1_Toggle = 0x04,
    INT1_Falling = 0x08,
    INT1_Rising = 0x0c,
    INT2_Falling = 0x00,
    INT2_Rising = 0x40,
            
}ext_INT_mode;

typedef enum{
    INT0 = 0x40,
    INT1 = 0x80,
    INT2 = 0x20,
}ext_INT_select;

void external_INT_enable(ext_INT_mode mode, ext_INT_select sel);
void external_INT_disable(ext_INT_select sel);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

