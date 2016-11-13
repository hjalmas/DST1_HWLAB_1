/* Includes -------------------------------------------------------------------*/
#include "main.h"
#include "assignments.h"

/* Variables ------------------------------------------------------------------*/

/* Definitions ----------------------------------------------------------------*/

/* Prototypes -----------------------------------------------------------------*/
extern int main2(int argc, char* argv[]);
extern int main3(int argc, char* argv[]);


/* Compiler stuff -------------------------------------------------------------*/
/**
 * Sample pragmas to cope with warnings. Please note the related line at
 * the end of this function, used to pop the compiler diagnostics status.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"


/* Main -----------------------------------------------------------------------*/

/**
 * Normally at this stage most of the microcontroller subsystems, including
 * the clock, were initialised by the CMSIS SystemInit() function invoked
 * from the startup file, before calling main().
 * (see system/src/cortexm/_initialize_hardware.c)
 */
int main(int argc, char* argv[]) {

	// Disable watchdog timer
	WDT->WDT_MR = WDT_MR_WDDIS;

	//Print simple message through SWD debugger.
#ifdef DEBUG
	trace_puts("DEBUG is running...\n");
#endif

	//Call different main() based on the selected assignment in "assignment.h".
#ifdef Assignment_1 | Assignment_2 | Assignment_3
	return main2(argc, argv);
#elif defined(Assignment_4)
	return main3(argc, argv);
#elif defined(Assignment_5)
	return main4(argc, argv);
#endif
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
