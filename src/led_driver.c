
#include "led_driver.h"

/**
 * Function to initialize the registers concerning the led.
 * Led connections:
 * Port:	PIOB
 * Pin:		PIO_PB25 (Arduino pin 2)
 */
void Init_Led(void) {
	//Disable pmc writeprotect
	PMC->PMC_WPMR |= 0x504D4300;
	//Enable PIOB peripheral clock
	PMC->PMC_PCER0 = PMC->PMC_PCSR0 | 1 << PIOB_IRQn;

	PIOB->PIO_WPMR |= 0x50494F00;
	//Enable Button peripheral
	PIOB->PIO_PER = PIO_PB25;
	//Enable output
	PIOB->PIO_OER = PIO_PB25;
	//Disable pullup
	PIOB->PIO_PUDR = PIO_PB25;
}

/**
 * Writes the value nLed to the previously configured led.
 * if nLed > 0 the led will turn on else it will turn off.
 *
 * Assumes the led connected to PIOB PIO_PB25 has been correctly
 * initialized.
 */
void Set_Led(unsigned int nLed) {
	if(nLed > 0) {
		PIOB->PIO_SODR = PIO_PB25;
	} else {
		PIOB->PIO_CODR = PIO_PB25;
	}
}

/**
 * Toggles the led.
 *
 * Assumes that the led has been initialized.
 */
void Toggle_Led(void) {
	if(PIOB->PIO_ODSR & PIO_PB25) {
		Set_Led(0);
	} else {
		Set_Led(1);
	}
}
