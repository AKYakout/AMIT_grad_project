/*
 * File:   atmega32_UART.c
 * Author: AKYakout
 *
 * Created on June 15, 2020, 7:34 PM
 */


#include "atmega32_UART.h"


void UART_init(uint32 baudRate){
    
    UCSRB |= (1<<3) | (1<<4) | (1<<7);
    uint16 divider = (F_CPU/16.0/baudRate)-1;
    UBRRL = (uint8)(divider);
    UBRRH = (uint8)(divider>>8);
    
    
    
}
uint8 UART_Rx_char(){
    while(ISBITCLEAR(UCSRA,7)){}
        return UDR;
}
void UART_Tx_char(uint8 data){
    while(ISBITCLEAR(UCSRA,5)){}
        UDR = data;

}

void UART_Tx_string(uint8 *data){
    for(uint8 i=0; data[i] != '\n'; i++){
        UART_Tx_char(data[i]);
    }
    return;
}