/*
 * SysTick_driver.h
 *
 *  Created on: Nov 3, 2016
 *      Author: root
 */

#ifndef INCLUDE_SYSTICK_DRIVER_H_
#define INCLUDE_SYSTICK_DRIVER_H_

/* Includes --------------------------------------------------------------*/
#include <stdio.h>
#include "diag/Trace.h"
#include "cmsis_device.h"
#include "sam3x_conf.h"

/* Defines ---------------------------------------------------------------*/

/* Prototypes ------------------------------------------------------------*/


/**
 * Initializes the SysTick timer.
 * the ticks value can be max 2^24.
 */
void SysTick_Init(uint32_t ticks);

/**
 * Start the SysTick timer.
 */
void SysTick_Start(void);

/**
 * Stop the SysTick timer.
 */
void SysTick_Stop(void);


#endif /* INCLUDE_SYSTICK_DRIVER_H_ */
