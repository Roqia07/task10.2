/*
 * File:   PWM.c
 * Author: mahmo
 *
 * Created on 02 September 2024, 14:57
 */


#include <xc.h>

void PWM_init() {
    DDRB |= (1<<DDB1);
    TCCR1A |= (1<<COM1A1) | (1<<WGM10) | (1<<WGM11);
    TCCR1B |= (1<<CS10);
    TCNT1 = 0;
    
    
    OCR1AH = 0;
    OCR1AL = 0;
    
    ADCSRA = 0x86;
}

