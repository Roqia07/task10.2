/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <avr/io.h>

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1
// Port B Pin Definitions
#define PORT_B0 0
#define PORT_B1 1
#define PORT_B2 2
#define PORT_B3 3
#define PORT_B4 4
#define PORT_B5 5
#define PORT_B6 6
#define PORT_B7 7

// Port C Pin Definitions
#define PORT_C0 8
#define PORT_C1 9
#define PORT_C2 10
#define PORT_C3 11
#define PORT_C4 12
#define PORT_C5 13
#define PORT_C6 14

// Port D Pin Definitions
#define PORT_D0 15
#define PORT_D1 16
#define PORT_D2 17
#define PORT_D3 18
#define PORT_D4 19
#define PORT_D5 20
#define PORT_D6 21
#define PORT_D7 22

// Macros for GPIO Manipulation
#define SET_BIT_POS(REG, POS)    (REG |= (1 << POS))
#define SET_BIT(REG, BIT)       (REG |= (1 << BIT))
#define CLEAR_BIT_POS(REG, POS) (REG &= ~(1 << POS))
#define CLEAR_BIT(REG, BIT)      (REG &= ~(1 << BIT))
#define READ_PIN_STATE(REG, POS) ((REG & (1 << POS)) ? HIGH : LOW)
#define SET_PIN_DIRECTION(DDR, PIN, DIR) ((DIR) ? (SET_BIT_POS(DDR, PIN)) : (CLEAR_BIT_POS(DDR, PIN)))
#define WRITE_PIN(PORT, PIN, VALUE) ((VALUE) ? (SET_BIT(PORT, PIN)) : (CLEAR_BIT(PORT, PIN)))

void pinMode(uint8_t pin, uint8_t mode) {
    if (pin <= PORT_B7) {
        SET_PIN_DIRECTION(DDRB, pin, mode);
    } else if (pin <= PORT_C6) {
        pin -= 8;
        SET_PIN_DIRECTION(DDRC, pin, mode);
    } else {
        pin -= 15;
        SET_PIN_DIRECTION(DDRD, pin, mode);
    }
}

void Write(uint8_t pin, uint8_t value) {
    if (pin <= PORT_B7) {
        WRITE_PIN(PORTB, pin, value);
    } else if (pin <= PORT_C6) {
        pin -= 8;
        WRITE_PIN(PORTC, pin, value);
    } else {
        pin -= 15;
        WRITE_PIN(PORTD, pin, value);
    }
}


#endif	/* XC_HEADER_TEMPLATE_H */
