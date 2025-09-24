
/*
 * Author       : Edward Tladi
 * Student Num  : 21578198
 * Data Created : 24 September 2025
 * ====================================================================
 * Project      : AVR ADC Lab – Lab 3: Embedded Systems Design 2025
 * File         : adc.c / adc.h / main.c
 * Institution  : Tshwane University of Technology (TUT)
 * Course       : Advanced Diploma in Computer Systems Engineering
 * Module       : Embedded Systems Design (EBD117V)
 * Lab          : Lab 3 – ADC
 * Target MCU   : ATmega328P (Arduino Uno)
 * Clock        : 16 MHz
 * Compiler     : AVR-GCC
 * Build Tool   : Makefile
 *
 * Description  :
 *   This program demonstrates the initialization and usage of the
 *   ADC (Analog-to-Digital Converter) on the ATmega328P. The ADC
 *   value is read from a potentiometer and output to PORTB and PD0-PD1.
 *
 * Revision History :
 *   v1.0 - Initial Lab 3 implementation
 *
 * ====================================================================
 *
 * Copyright (c) 2025 Edward Tladi
 * All rights reserved. This work is part of Lab 3 for Embedded Systems Design (EBD117V) 2025.
 * Redistribution or use is allowed only for educational purposes within TUT.
 */

/*_____________________________Developer includes_____________________________*/
#include "adc.h"

/*_____________________________MAIN_________________________________________*/

int main(void)
{
    DDRB = 0xFF; // PORTB as output
    DDRD = 0x03; // PD0 & PD1 as output

    if (adc_init() != TUT_OK)
        return -1; // ADC initialization failed

    while (1)
    {
        TUT_U16 adc_value = 0x0000;
        TUT_ErrorCode status = adc_read(0, &adc_value);

        if (status == TUT_OK)
        {
            PORTB = (TUT_U8)(adc_value & 0xFF);                  // lower 8 bits
            PORTD = (PORTD & ~0x03) | ((adc_value >> 8) & 0x03); // upper 2 bits
        }
        else
        {
            // Error handling blink LED fast on PB0
            PORTB ^= (1 << PB0);
            _delay_ms(100);
        }

        _delay_ms(5);
    }
}
