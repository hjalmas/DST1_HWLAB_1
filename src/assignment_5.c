
/* Includes -------------------------------------------------------------------*/
#include <stdio.h>
#include "diag/Trace.h"
#include "cmsis_device.h"
#include "sam3x_conf.h"

#include "assignments.h"
#include "led_driver.h"
#include "SysTick_driver.h"
#include "button_driver.h"

/* Variables ------------------------------------------------------------------*/
static volatile uint32_t tickCnt = 0;

/* Definitions ----------------------------------------------------------------*/
#define EXIT_SUCCESS 1

/* Prototypes -----------------------------------------------------------------*/
#ifdef Assignment_5
void delay_ms(uint32_t time_ms);
#endif


/* Main -----------------------------------------------------------------------*/

/**
 * Normally at this stage most of the microcontroller subsystems, including
 * the clock, were initialised by the CMSIS SystemInit() function invoked
 * from the startup file, before calling main().
 * (see system/src/cortexm/_initialize_hardware.c)
 */
int main4(int argc, char* argv[]) {

	/* Initialize system */
	Init_Led();
	Init_Button_Interrupt();
	/* Interrupt each ms */
	SysTick_Init(SystemCoreClock/1000);
	SysTick_Start();

	volatile uint32_t lCnt = 0;

	/* Toggle the led with a frequency of 1Hz */
	while (1) {
#ifdef Assignment_5
		Toggle_Led();
		delay_ms(150);
#endif
	}

	return EXIT_SUCCESS;
}

/* Function declarations -------------------------------------------------------*/

#ifdef Assignment_5
/**
 * Function for handling sysTick interrupts.
 */
void SysTick_Handler(void) {
	tickCnt++;
}

/**
 * Called when an interrupt is detected from PIOB
 */
void PIOB_Handler() {
	volatile uint32_t isr = Button_Handler();

	//If the interrupt was triggered by the button
	if(isr & PIO_PB26) {
#ifdef DEBUG
		trace_puts("Button was pressed!\n");
#endif

		//If the SysTick timer is running then stop it
		if(SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) {
			SysTick_Stop();
		} else {
			SysTick_Start();
		}
	}
}

/**
 * Function that delays program execution for the specified amount of time.
 */
void delay_ms(uint32_t time_ms) {
	volatile uint32_t t0 = tickCnt;
	while(t0 + time_ms > tickCnt){};
}
#endif


#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

