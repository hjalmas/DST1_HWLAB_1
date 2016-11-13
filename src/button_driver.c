#include "button_driver.h"

/**
 * Function to initialize peripheral registers concerning the button.
 * Button connections:
 * Port: 	PIOB
 * Pin:		PIO_PB26 (Arduino pin 22)
 */
void Init_Button(void) {
#ifdef DEBUG
	trace_puts("Initializing button...\n");
#endif

	//Disable pmc writeprotect
	PMC->PMC_WPMR = 0x504D4300;
	//Enable PIOB peripheral clock
	PMC->PMC_PCER0 = PMC->PMC_PCSR0 | 1 << PIOB_IRQn;

	PIOB->PIO_WPMR = 0x50494F00;
	//Enable Button peripheral
	PIOB->PIO_PER = PIO_PB26;
	//Disable output
	PIOB->PIO_ODR = PIO_PB26;
	//Disable pullup
	PIOB->PIO_PUDR = PIO_PB26;
}

/**
 * Reads the current value of the button and
 * stores the value 0 in the memory adress pointed to by
 * *nButton if the button is pressed, else 1.
 *
 * Assumes that the button has been correctly initialized.
 */
void ReadButton(unsigned int* nButton) {
	//Read Output status register
	*nButton = (PIOB->PIO_PDSR & PIO_PB26) >> 26;
}

/**
 * Function to initialize peripheral registers concerning the button.
 * Together with interrupt and debounce.
 * Button connections:
 * Port: 	PIOB
 * Pin:		PIO_PB26 (Arduino pin 22)
 */
void Init_Button_Interrupt(void) {
	//Disable pmc writeprotect
	PMC->PMC_WPMR = 0x504D4300;
	//Enable PIOB peripheral clock
	PMC->PMC_PCER0 = 1 << PIOB_IRQn;

	//Disable writeprotect
	PIOB->PIO_WPMR = 0x50494F00;
	//Enable Button peripheral
	PIOB->PIO_PER = PIO_PB26;
	//Disable output
	PIOB->PIO_ODR = PIO_PB26;
	//Disable pullup
	PIOB->PIO_PUDR = PIO_PB26;

	//Set up slow clock divide fo c:a 16ms debounce
	PIOB->PIO_SCDR = 261;
	//Enable the input filter in debounce mode
	PIOB->PIO_DIFSR = PIO_PB26;
	//Enable input filter
	PIOB->PIO_IFER = PIO_PB26;
	//Enable interrupts on edge
	PIOB->PIO_ESR = PIO_PB26;
	//Enable interrupts on falling edge
	PIOB->PIO_FELLSR = PIO_PB26;
	//Enable additional interrupts mode
	PIOB->PIO_AIMER = PIO_PB26;
	//Enable the pio to send IRQ to nvic
	PIOB->PIO_IER = PIO_PB26;

	//Enable interrupts in nvic
	NVIC_EnableIRQ(PIOB_IRQn);

}

/**
 * Handles entry of ISR
 * Should be called in beginning of ISR.
 * returns the value in the interrupt status register.
 */
uint32_t Button_Handler(void) {
	//Clear pending interrupt
	NVIC_ClearPendingIRQ(PIOB_IRQn);
	//Read PIOB ISR which also clears the flag
	return PIOB->PIO_ISR;
}
