
#include "SysTick_driver.h"

/**
 * Initializes the SysTick timer.
 * the ticks value can be max 2^24.
 */
void SysTick_Init(uint32_t ticks) {
	//Disable systick
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_COUNTFLAG_Msk);
	//Set up SysTick
	SysTick->LOAD = ticks-1;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
}

/**
 * Start the SysTick timer.
 */
void SysTick_Start(void) {
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/**
 * Stop the SysTick timer.
 */
void SysTick_Stop(void) {
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
