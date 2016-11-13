
/* Includes -------------------------------------------------------------------*/
#include <stdio.h>
#include "diag/Trace.h"
#include "cmsis_device.h"
#include "sam3x_conf.h"

#include "assignments.h"
#include "led_driver.h"
#include "button_driver.h"

/* Variables ------------------------------------------------------------------*/

/* Definitions ----------------------------------------------------------------*/
#define EXIT_SUCCESS 1
#define PMC_WPKEY 0x504D43

/* Prototypes -----------------------------------------------------------------*/

/* Main -----------------------------------------------------------------------*/

/**
 * Normally at this stage most of the microcontroller subsystems, including
 * the clock, were initialised by the CMSIS SystemInit() function invoked
 * from the startup file, before calling main().
 * (see system/src/cortexm/_initialize_hardware.c)
 */
int main2(int argc, char* argv[]) {

	//Initialize system
	Init_Button();
	Init_Led();

	unsigned int btnState;
	while (1) {
		ReadButton(&btnState);
		Set_Led(!btnState);
	}

	return EXIT_SUCCESS;
}

/* Function declarations -------------------------------------------------------*/

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
