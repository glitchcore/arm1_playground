BUILD_DIR = build
TARGET = test

C_SOURCES = main.c

ASM_SOURCES = startup.s

#######################################
# binaries
#######################################
BINPATH = /usr/bin/
PREFIX = arm-none-eabi-
# CC = pcc
GCC = $(BINPATH)/$(PREFIX)gcc
CC = $(GCC)
AS = $(BINPATH)/$(PREFIX)gcc
CP = $(BINPATH)/$(PREFIX)objcopy
DUMP = $(BINPATH)/$(PREFIX)objdump -D
AR = $(BINPATH)/$(PREFIX)ar
SZ = $(BINPATH)/$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

CFLAGS = -Wall -O0 -march=armv2 -mcpu=arm2

LDSCRIPT = link.ld

LDFLAGS = -specs=nano.specs -T$(LDSCRIPT) -nostartfiles

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).dump.s

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(GCC) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/$(TARGET).dump.s: $(BUILD_DIR)/$(TARGET).elf
	$(DUMP) $< > $@


clean:
	-rm -fR .dep $(BUILD_DIR)
