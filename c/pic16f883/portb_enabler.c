// Dylan Nelson
// June 27, 2024
// pic16f883
// portb_enabler.c

#include <xc.h>
#include <stdint.h>

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

void main() {
    // Initialize 8 MHz internal oscillator.
    OSCCON = 0b01110000;

    // Set the ports to be digital.
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;
    // Disable the tri-state outputs for PortB so they can be digital outputs.
    TRISB = 0b00000000;

    // main while loop for the program
    while (1) {
        // Turn on every other port on PortB.
        PORTB = 0b10101010;
    }
}
