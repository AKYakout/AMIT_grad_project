/*
 * File:   atmega32_ADC.c
 * Author: AKYakout
 *
 * Created on May 3, 2020, 8:24 PM
 */


#include "atmega32_ADC.h"

void ADC_init(ADC_REF_volt_SEL refSel, ADC_prescale_factor preS, ADC_trigger_source tSource, ADC_INT_state intState) {
    
    ADMUX |= refSel;
    ADCSRA |= preS | intState;
       switch(tSource) {
               case singleConv:
                   break;
               default:
                   ADCSRA |= (1<<5);
                   SFIOR &= 0x1f;
                   SFIOR |= tSource;
       }
       
    ADCSRA |= (1<<7);
}



uint16 ADC_singleRead(ADC_Channel ch, ADC_RES Res) {
    
    ADMUX &= 0xe0;
    ADMUX |= ch;
    switch(Res) {
        case ADC_8BIT:
            ADMUX |= (1<<5);
            ADCSRA |= (1<<6);
            while(ISBITCLEAR(ADCSRA,4))
                ADCSRA |= (1<<4);
                return 0x0000 | ADCH;
                break;
        case ADC_10BIT:
            ADCSRA |= (1<<6);
            while(ISBITCLEAR(ADCSRA,4))
                ADCSRA |= (1<<4);
                return ADCL | (ADCH<<8);
                break;
            
}
    return 0;
}