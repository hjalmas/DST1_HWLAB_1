
/* Includes -------------------------------------------------------------------*/
#include <stdio.h>
#include "diag/Trace.h"
#include "cmsis_device.h"
#include "sam3x_conf.h"

#include "assignments.h"
#include "led_driver.h"
#include "SysTick_driver.h"

/* Variables ------------------------------------------------------------------*/
static volatile uint32_t tickCnt = 0;

/* Definitions ----------------------------------------------------------------*/
#define EXIT_SUCCESS 1

/* Prototypes -----------------------------------------------------------------*/
#ifdef Assignment_4
void delay_ms(uint32_t time_ms);
#endif


/* Main -----------------------------------------------------------------------*/

/**
 * Normally at this stage most of the microcontroller subsystems, including
 * the clock, were initialised by the CMSIS SystemInit() function invoked
 * from the startup file, before calling main().
 * (see system/src/cortexm/_initialize_hardware.c)
 */
int main3(int argc, char* argv[]) {

	/* Initialize system */
	Init_Led();
	/* Interrupt each ms */
	SysTick_Init(SystemCoreClock/1000);
	SysTick_Start();

	volatile uint32_t lCnt = 0;

	/* Toggle the led with a frequency of 1Hz */
	while (1) {

#ifdef DEBUG
		lCnt++;
		trace_printf("Number of led toggles: %d\n", lCnt);
#endif
#ifdef Assignment_4
		Toggle_Led();
		delay_ms(500);
#endif
	}

	return EXIT_SUCCESS;
}

/* Function declarations -------------------------------------------------------*/

#ifdef Assignment_4
/**
 * Function for handling sysTick interrupts.
 */
void SysTick_Handler(void) {
	tickCnt++;
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

