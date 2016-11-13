/*
 * button_driver.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Albin
 */

#ifndef INCLUDE_BUTTON_DRIVER_H_
#define INCLUDE_BUTTON_DRIVER_H_

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
 * Function to initialize peripheral registers concerning the button.
 * Button connections:
 * Port: 	PIOB
 * Pin:		PIO_PB26 (Arduino pin 22)
 */
void Init_Button(void);

/**
 * Reads the current value of the button and
 * stores the value 0 in the memory adress pointed to by
 * *nButton if the button is pressed, else 1.
 *
 * Assumes that the button has been correctly initialized.
 */
void ReadButton(unsigned int *nButton);

/**
 * Function to initialize peripheral registers concerning the button.
 * Together with interrupt and debounce.
 * Button connections:
 * Port: 	PIOB
 * Pin:		PIO_PB26 (Arduino pin 22)
 */
void Init_Button_Interrupt(void);

/**
 * Handles entry of ISR
 */
uint32_t Button_Handler(void);



#endif /* INCLUDE_BUTTON_DRIVER_H_ */
