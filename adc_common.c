#include "p33fj16gs504.h"

#define CONVERSION_PAIRS 2
void ConvPair0Handler (void); // Declare the pair conversion handlers
void ConvPair1Handler (void);

void (*jumpTable[CONVERSION_PAIRS * 2 -1])(void);

void InitADC_Common()
{
	jumpTable[0] = &ConvPair0Handler; /* Set up the jump table*/
	jumpTable[2] = &ConvPair1Handler;
	ADCONbits.FORM = 1; // Output in Integer Format
	ADCONbits.EIE = 1; // Enable Early Interrupt
	ADCONbits.ORDER = 0; // Normal Order of conversion
	ADCONbits.SEQSAMP = 0; // Simultaneous sampling 
	ADCONbits.ASYNCSAMP = 1; // Asynchronous sampling
	ADCONbits.SLOWCLK = 0; // High Frequency Clock input
	ADCONbits.ADCS = 5; // Clock divider selection
	ADCPC0bits.TRGSRC0=0b00100;// PWM Generator 1 Primary Trigger Selected
	ADCPC0bits.IRQEN0=1; // Enable common ADC Interrupt for Pair 0
	ADCPC0bits.TRGSRC1=0b00101;// PWM Generator 2 Primary Trigger Selected
	ADCPC0bits.IRQEN1=1; // Enable common ADC Interrupt for Pair 1
	ADPCFGbits.PCFG0 = 0; // AN0 is configured as analog input
	ADPCFGbits.PCFG1 = 0; // AN1 is configured as analog input
	ADPCFGbits.PCFG2 = 0; // AN2 is configured as analog input
	ADPCFGbits.PCFG3 = 0; // AN3 is configured as analog input
	IPC3bits.ADIP = 0x01; // Set Common ADC Interrupt Priority Level (Level 1)
	IFS0bits.ADIF = 0; // Clear ADC Pair 0 Interrupt Flag
	IEC0bits.ADIE = 1; // Enable ADC Pair 0 Interrupt
	ADCONbits.ADON = 1; // Enable ADC module
}

/* Example code for ADC ISR*/
void __attribute__((interrupt, no_auto_psv)) _ ADCInterrupt (void)
{
	IFS0bits.ADIF = 0; // Clear ADC Pair 0 Interrupt Flag
	((void (*)())*((int*)ADBASE))(); // Call the corresponding handler
}

void ConvPair0Handler (void)
{
	int an0, an1;
	an0 = ADCBUF0; // Read AN0 conversion result
	an1 = ADCBUF1; // Read AN1 conversion result 
	ADSTATbits.P0RDY = 0; // Clear the ADSTAT bits 
}

void ConvPair1Handler (void)
{
	int an2, an3;
	an2 = ADCBUF2; // Read AN2 conversion result
	an3 = ADCBUF3; // Read AN3 conversion result 
	ADSTATbits.P1RDY = 0; // Clear the ADSTAT bits
}
