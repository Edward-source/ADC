# AVR ADC & W5100 SPI Communication – Embedded Systems Lab 3

**Author:** Edward Tladi  
**Target MCU:** ATmega328P (Arduino Uno)  
**Toolchain:** AVR-GCC, Makefile  
**Simulation / Hardware:** Proteus 8.15 / Arduino Uno with W5100 Ethernet Shield  

---

## Overview

This project demonstrates low-level embedded systems programming on the ATmega328P using **raw C with AVR-GCC** and structured Makefiles. The main objectives are:

1. **Analog-to-Digital Conversion (ADC)**  
   - Read analog signals (0–5V) from sensors using the ATmega328P ADC.  
   - Output the 10-bit ADC result on GPIO pins (PORTB and PORTD).  

2. **SPI Communication with W5100 Ethernet Shield**  
   - Initialize SPI as master and communicate with the W5100 at register level.  
   - Perform basic read/write operations without relying on Arduino libraries.  

3. **Professional Firmware Practices**  
   - Modular code with **separate header (`include/`) and source (`src/`) files**.  
   - Makefile-based build system for compilation, linking, and flashing.  
   - Register-level programming with minimal abstractions.  

---

## Learning Outcomes

- Configure and use **ATmega328P peripherals**: ADC, SPI, GPIO.  
- Write **modular, maintainable embedded C code**.  
- Understand **low-level hardware control** without Arduino abstractions.  
- Build projects using **GNU toolchain and Makefiles**.  
- Simulate circuits and microcontroller behavior in **Proteus 8.15**.  

---

## File Structure

