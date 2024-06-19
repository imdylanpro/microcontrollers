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

// Function to initialize ADC
void initADC() {
    // Set AN0 (RA0) as analog input
    ANSEL = 0b00000001;
    ANSELH = 0;
    
    // Configure ADC
    ADCON0 = 0b00000001; // Select channel AN0, enable ADC
    ADCON1 = 0b00000000; // Vref+ = VDD, Vref- = VSS
}

// Function to read ADC value
uint16_t readADC() {
    GO_nDONE = 1; // Start ADC conversion
    while (GO_nDONE); // Wait for conversion to complete
    return (uint16_t)((ADRESH << 8) | ADRESL); // Combine ADRESH and ADRESL
}

// Function to initialize ports
void initPorts() {
    TRISB = 0; // Set all RB pins as output
    PORTB = 0; // Clear PORTB
}

void main() {
    // Initialize oscillator, ADC, and ports
    OSCCON = 0b01110000; // 8 MHz internal oscillator
    initADC();
    initPorts();
    
    while (1) {
        uint16_t adcValue = readADC(); // Read ADC value
        PORTB = adcValue; // Output ADC value to RB0-RB7
    }
}

