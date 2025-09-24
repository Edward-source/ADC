# =============================
# AVR Project Makefile
# =============================

# MCU / Compiler / Options
MCU      = atmega328p
F_CPU    = 16000000UL
CC       = avr-gcc
OBJCOPY  = avr-objcopy

# Include directory
INC_DIR  = include
CFLAGS   = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -I$(INC_DIR)

# Source files
SRC_DIR  = src
SRC      = $(SRC_DIR)/main.c $(SRC_DIR)/adc.c
OBJ      = $(SRC:.c=.o)
TARGET   = main

# Programmer settings
PROGRAMMER = arduino
PORT       = /dev/ttyACM0
BAUD       = 115200

# =============================
# Build all
# =============================
all: $(TARGET).hex

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into ELF
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Convert ELF to HEX
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash to Arduino
flash: $(TARGET).hex
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$<:i

# Clean build files
clean:
	rm -f $(SRC_DIR)/*.o *.elf *.hex
	rm -f $(INC_DIR)/*~