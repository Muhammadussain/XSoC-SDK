.PHONY: all clean

CC = riscv32-unknown-elf-gcc
OBJCOPY = riscv32-unknown-elf-objcopy
OBJDUMP_TOOL = riscv32-unknown-elf-objdump

TARGET = kyber_demo
OUT_DIR = out

# Source files: demo + SDK sources + memcpy (now self-contained)
SRC = examples/$(TARGET).c src/babykyber.c src/babykyber_hal.c src/memcpy.c

# Include directories
INC = -Iinclude

# Compiler flags (exactly same as nucleusrv approach)
CFLAGS = -O0 -static -mcmodel=medany -fvisibility=hidden -nostdlib -nostartfiles -g -march=rv32if -mabi=ilp32f

# Linker script (now self-contained in XSoC-SDK)
LDFLAGS = -T linker/link.ld

# Output files (same naming convention as nucleusrv approach)
ELF = $(OUT_DIR)/$(TARGET)
OBJDUMP_FILE = $(OUT_DIR)/$(TARGET).objdump
IMEM_BIN = $(OUT_DIR)/imem.bin
DMEM_BIN = $(OUT_DIR)/dmem.bin
IMEM_HEX = $(OUT_DIR)/imem.hex
DMEM_HEX = $(OUT_DIR)/dmem.hex

all: clean $(OUT_DIR) $(ELF) $(OBJDUMP_FILE) $(IMEM_BIN) $(DMEM_BIN) $(IMEM_HEX) $(DMEM_HEX)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(ELF): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INC) -o $@ $^

$(OBJDUMP_FILE): $(ELF)
	$(OBJDUMP_TOOL) -d -Mno-aliases $< > $@

$(IMEM_BIN): $(ELF)
	$(OBJCOPY) -O binary -j .text $< $@

$(DMEM_BIN): $(ELF)
	$(OBJCOPY) -O binary -j .data $< $@

$(IMEM_HEX): $(IMEM_BIN)
	hexdump -v -e '1/4 "%08x\n"' $< > $@

$(DMEM_HEX): $(DMEM_BIN)
	hexdump -v -e '1/4 "%08x\n"' $< > $@

clean:
	rm -rf $(OUT_DIR)