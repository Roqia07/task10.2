#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL // Clock frequency

int main(void) {
    // SPI initialization
    DDRB |= (1 << PB2) | (1 << PB3) | (1 << PB5); // Set PB2 (SS), PB3 (MOSI), and PB5 (SCK) as outputs
    DDRB &= ~(1 << PB4); // Set PB4 (MISO) as input
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master mode, set clock rate fck/16

    // Example message to send
    char message[] = "Hello, world!";
    int message_length = sizeof(message) - 1; // Exclude null terminator

    for (int i = 0; i < message_length; i++) {
        SPDR = message[i]; // Load data into the SPI data register
        while (!(SPSR & (1 << SPIF)));  // Wait for transmission complete
    }

    while (1) {
        // Keep the MCU running
    }

    return 0;
}
