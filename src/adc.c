/*
* Author: Edward Tladi

* Date Created: 2025-09-24
* Description: ADC driver for AVR microcontrollers.
*              Provides initialization and reading functions.
*
*/

// Developer includes
#include "adc.h"

static TUT_U8 adc_initialized = 0; // track init status

TUT_ErrorCode adc_init(void)
{
    // Reference = AVcc (5V), result right-adjusted
    ADMUX = (1 << REFS0);

    // Enable ADC, prescaler = 128 → 125 kHz ADC clock
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    adc_initialized = 1;
    return TUT_OK;
}

TUT_ErrorCode adc_read(TUT_U8 channel, TUT_U16 *result)
{
    if (!adc_initialized)
        return TUT_ERR_NOT_INITIALIZED;

    if (channel > 7)
        return TUT_ERR_INVALID_CHANNEL;

    // Select channel safely
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);

    // Start conversion
    ADCSRA |= (1 << ADSC);

    // Add timeout protection
    TUT_U32 timeout = 100000UL;
    while ((ADCSRA & (1 << ADSC)) && --timeout)
        ;

    if (timeout == 0)
        return TUT_ERR_TIMEOUT;

    *result = ADC; // 10-bit result (0–1023)
    return TUT_OK;
}
