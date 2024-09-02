# task10.2
## Motor Speed Control Using ATmega328P
## contents:
  - [GPIO](#gpio)
  - [ADC](#adc)
  - [TIMER](#timer)
  - [External Interrupts](#external-interrupts)
  - [SPI Protocol](#spi-protocol)

### GPIO

- The GPIO.h is used to ease the readability of the code 

### ADC

- The ADC is used to read the analog value from the potentiometer, which is then converted to a digital value for motor speed control.

### TIMER

- TIMER1 is configured in CTC (Clear Timer on Compare Match) mode to generate a PWM signal for motor speed control.
- The timer1 is also  in CTC to interrupt each 1 sec  while using a prescalar =1024 and using CPU-freq =16 MHZ which sets the OCR1A=15624 to count a 1 sec then interrupt

### External Interrupts

-  INT1 are used to capture the encoder pulses, allowing the calculation of the motor's RPM , while assuming that the encoder's pulses per revolution(PPR)=24.
### SPI Protocol

- The SPI protocol is implemented to communicate the motor speed data to the SPI debugger in PROTEUS.


