// Dylan Nelson
// June 27, 2024
// pic16f883
// adc.c

#include <xc.h>
#include <stdint.h>
#include <time.h>

// Configuration bits
#pragma config FOSC = INTRC_CLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog timer disabled
#pragma config PWRTE = OFF      // Power-up timer disabled
#pragma config MCLRE = OFF      // MCLR pin function is digital input
#pragma config CP = OFF         // Code protection disabled
#pragma config CPD = OFF        // Data code protection disabled
#pragma config BOREN = OFF      // Brown-out reset disabled
#pragma config IESO = OFF       // Internal/external oscillator switchover disabled
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor disabled

void setup() {
    // Initialize 8 MHz internal oscillator.
    OSCCON = 0b01110000;

    // Set the ports to be digital, except for AN0 which is our ADC input.
    ANSEL = 0b00000001;
    ANSELH = 0b00000000;
    // Disable the tri-state option for PortB and enable tri-state for PortA bit 1.
    TRISB = 0b00000000;
    TRISA = 0b00000001;
    
    // ADC Setup, set the analog input as AN0, Clock = FOSC /2, ADON set.
    ADCON0 = 0b00000001;
    // ADC Setup, Left justified, VSS and ADD as reference.
    ADCON1 = 0b00000000;        
}

void main() {
    
    // Call setup
    setup();
    
    // main while loop for the program
    while (1) {
        // Turn on every other port on PortB.
        PORTB = 0b00010000;
        
        PORTB = 0b00000000;
    }
}
