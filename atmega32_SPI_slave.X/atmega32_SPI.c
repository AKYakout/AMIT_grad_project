/*
 * File:   atmega32_SPI.c
 * Author: AKYakout
 *
 * Created on June 20, 2020, 5:08 AM
 */


#include "atmega32_SPI.h"

void SPI_MASTER_init(){
    SPCR |= (1<<4)| (3<<0);
    SPCR |= (1<<6)|(1<<7);
}
void SPI_MASTER_write(uint8 data){
    SPDR = data;
    while(ISBITCLEAR(SPSR,7));
}
void SPI_slave_init(){
    SPCR |= (3<<0);
    SPCR |= (1<<6) | (1<<7);
}
uint8 SPI_slave_read(){
    while(ISBITCLEAR(SPSR,7));
    return SPDR;
}