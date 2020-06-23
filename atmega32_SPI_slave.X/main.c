/*
 * File:   main.c
 * Author: AKYakout
 *
 * Created on June 20, 2020, 8:04 PM
 */


#include "atmega32_SPI.h"
#include <avr/interrupt.h>

uint8 SPI_Rx_data = 0;

ISR(SPI_STC_vect){
    SPI_Rx_data = SPDR;
      switch(SPI_Rx_data){
            case '1':
                GPIO_OUTPUT_Handle(GPIOD, PIN6,HIGH);
                GPIO_OUTPUT_Handle(GPIOD, PIN7,LOW);
                
                break;
            case '2':
                GPIO_OUTPUT_Handle(GPIOD, PIN6,LOW);
                GPIO_OUTPUT_Handle(GPIOD, PIN7,HIGH);
                
                break;
            case '3':
                GPIO_OUTPUT_Handle(GPIOD, PIN6,LOW);
                GPIO_OUTPUT_Handle(GPIOD, PIN7,LOW);
                
                break;
            case '4':
                GPIO_OUTPUT_Handle(GPIOD, PIN6,HIGH);
                GPIO_OUTPUT_Handle(GPIOD, PIN7,HIGH);
                
                break;
            default:
                break;
        }
}
int main(void) {
    
    GPIO_directionSet(GPIOD, PIN6,OUTPUT);
    GPIO_directionSet(GPIOD, PIN7,OUTPUT);      // configure LEDs as OUTPUT
    
    GPIO_directionSet(GPIOB, PIN6,OUTPUT);      // configure MISO as OUTPUT     
    
    SPI_slave_init();                           // initialize SPI as slave
    
    GL_INTERRUPT_ENABLE();
    
    while(1){
      
    }
    return 0;
}
