/*
 * Author: Edward Tladi
 * Date Created: 2025-09-24
 * Description: Header file for ADC module
 * adc.h - Header file for ADC module
 */

#ifndef ADC_H
#define ADC_H

#include <avr/io.h>
#include <util/delay.h>

// Developer includes
#include "error.h"

#define F_CPU 16000000UL

// Function to initialize the ADC
TUT_ErrorCode adc_init(void);

// Function to read the ADC value
TUT_ErrorCode adc_read(TUT_U8 channel, TUT_U16 *result);

#endif