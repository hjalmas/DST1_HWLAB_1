/*
 * led_driver.h
 *
 *  Created on: Nov 3, 2016
 *      Author: root
 */

#ifndef INCLUDE_LED_DRIVER_H_
#define INCLUDE_LED_DRIVER_H_

/* Includes --------------------------------------------------------------*/
#include <stdio.h>
#include "diag/Trace.h"
#include "cmsis_device.h"
#include "sam3x_conf.h"

/* Defines ---------------------------------------------------------------*/
#define PIOB_WPKEY 0x50494F
#define PMC_WPKEY 0x504D43

/* Prototypes ------------------------------------------------------------*/
/**
 * Function to initialize the registers concerning the led.
 * Led connections:
 * Port:	PIOB
 * Pin:		PIO_PB25 (Arduino pin 2)
 */
void Init_Led(void);

/**
 * Writes the value nLed to the previously configured led.
 * if nLed > 0 the led will turn on else it will turn off.
 *
 * Assumes the led connected to PIOB PIO_PB25 has been correctly
 * initialized.
 */
void Set_Led(unsigned int nLed);

/**
 * Toggles the led.
 *
 * Assumes that the led has been initialized.
 */
void Toggle_Led(void);


#endif /* INCLUDE_LED_DRIVER_H_ */
