
#include <xc.h>
#include "INT1.h"
#include "timer.h"
#define PPR  24
#define F_CPU 16000000UL
int count=0;
int rpm =0;
ISR(INT1_vect){
    count++;
}
ISR(TIMER1_COMPA_vect) {
    rpm = count/PPR*60;  // Calculate RPS (Revolutions Per Second)
    count = 0;    // Reset count for the next second
}
void main(void) {
    
    while (1){
        
    }
    return;
}
