/*
 * File:   GPIO_test.c
 * Author: mahmo
 *
 * Created on August 31, 2024, 3:38 PM
 */


#include <xc.h>
#include "ADC.h"
#include "PWM.h"
#include <avr/delay.h>




unsigned int read_adc(void){
    ADMUX |= (1<<REFS0);
    ADMUX |= 0b0010;
    _delay_us(10);
    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    ADCSRA |= (1<<ADIF);
    return ADCW;
    
}



void main(void) {
    int convert_value = 0;
    
    //PWM 
    
    PWM_init();
    while(1) {
        convert_value = read_adc();
        OCR1AH = (convert_value >> 8);
        OCR1AL = (convert_value);
    }
    
}



