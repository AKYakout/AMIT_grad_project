/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

 
#ifndef ATMEGA32_UART_H
#define	ATMEGA32_UART_H

#include "atmega32_timers.h"

#define     UDR       (*(vuint8 *)0x2c)
#define     UCSRA     (*(vuint8 *)0x2b)
#define     UCSRB     (*(vuint8 *)0x2a)
#define     UCSRC     (*(vuint8 *)0x40)
#define     UBRRL     (*(vuint8 *)0x29)
#define     UBRRH     (*(vuint8 *)0x40)

void UART_init(uint32 baudRate);
uint8 UART_Rx_char();
void UART_Tx_char(uint8 data);
//uint8* UART_Rx_string();
void UART_Tx_string(uint8 *data);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

