.PHONY: all clean

CC = riscv64-unknown-elf-gcc
OBJCOPY = riscv64-unknown-elf-objcopy
OBJDUMP_TOOL = riscv64-unknown-elf-objdump

TARGET = kyber_demo
OUT_DIR = out

# Source files: demo + SDK sources (removed memcpy as per user request)
SRC = examples/$(TARGET).c src/babykyber.c src/babykyber_hal.c

# Include directories
INC = -Iinclude

# Compiler flags (RV32IF, no stdlib)
CFLAGS = -O0 -static -mcmodel=medany -fvisibility=hidden -nostdlib -nostartfiles -g -march=rv32if -mabi=ilp32f

# Output files
ELF = $(OUT_DIR)/babykyber.elf
OBJDUMP_FILE = $(OUT_DIR)/babykyber.objdump
IMEM_BIN = $(OUT_DIR)/babykyber_imem.bin
DMEM_BIN = $(OUT_DIR)/babykyber_dmem.bin
IMEM_HEX = $(OUT_DIR)/babykyber_imem.hex
DMEM_HEX = $(OUT_DIR)/babykyber_dmem.hex

all: clean $(OUT_DIR) $(ELF) $(OBJDUMP_FILE) $(IMEM_BIN) $(DMEM_BIN) $(IMEM_HEX) $(DMEM_HEX)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(ELF): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(INC)

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