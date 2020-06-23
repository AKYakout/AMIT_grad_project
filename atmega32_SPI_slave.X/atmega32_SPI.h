/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ATMEGA32_SPI_H
#define	ATMEGA32_SPI_H

#include "atmega32_UART.h"

#define     SPCR     (*(vuint8 *)0x2d)
#define     SPSR     (*(vuint8 *)0x2e)
#define     SPDR     (*(vuint8 *)0x2f)

void SPI_MASTER_init();
void SPI_MASTER_write(uint8 data);
void SPI_slave_init();

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

