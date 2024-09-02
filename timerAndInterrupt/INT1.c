#include <xc.h>
#include "INT1.h"

void interrupt_init()
{
    EICRA |=(1<<ISC11) | (1<<ISC10);
    EIMSK |= 1<<INT1;
    sei();
    
}