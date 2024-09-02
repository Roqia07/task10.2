#include <xc.h>
#include "timer.h"
// make timer 1 on CTC mode to interrupt on 1 sec
void timer1(){

    TCCR1B |= (1<< WGM12); 
    OCR1A=15624;

    TIMSK1 |= (1 << OCIE1A);
 
    TCCR1B |= (1<<CS12) | (1<<CS10);
}