# BabyKyber SDK

A software development kit for interfacing with the BabyKyber hardware accelerator, implementing a simplified version of the Kyber key encapsulation mechanism (KEM) for RISC-V based systems.

## Features

- Hardware abstraction layer for BabyKyber accelerator
- Key generation, encryption, and decryption functions
- Memory-mapped register interface
- RISC-V RV32IF compilation support

## Project Structure

```
├── include/                 # Header files
│   ├── babykyber.h         # Main API
│   ├── babykyber_hal.h     # Hardware Abstraction Layer
│   └── babykyber_regs.h    # Register definitions
├── src/                     # Source files
│   ├── babykyber.c         # API implementation
│   └── babykyber_hal.c     # HAL implementation
├── examples/                # Example programs
│   └── kyber_demo.c        # Demo application
├── Makefile                 # Build system
└── README.md               # This file
```

## Prerequisites

- RISC-V toolchain: `riscv64-unknown-elf-gcc`
- Make build system

## Building

Run `make` to build the demo and generate output files:

```bash
make
```

This will create the following files in the `out/` directory:

- `babykyber.elf` - RISC-V executable
- `babykyber.objdump` - Disassembly listing
- `babykyber_imem.bin` - Instruction memory binary
- `babykyber_dmem.bin` - Data memory binary
- `babykyber_imem.hex` - Instruction memory hex dump
- `babykyber_dmem.hex` - Data memory hex dump

## Usage

The SDK provides a simple API for cryptographic operations:

```c
#include "babykyber.h"

// Initialize
babykyber_init();

// Key generation
uint32_t A[4][4] = {
    {4,3,2,1},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
};
uint32_t s[2][4] = {
    {1, 16, 0, 1},
    {16, 0, 1, 16}
};
uint32_t e[2][4] = {
    {0,1,16,0},
    {1,16,0,1}
};
babykyber_keygen(A, s, e, BABYKYBER_KEYGEN_TRIGGER_ADDR);

// Encryption
uint32_t message = 42;
uint32_t r[2][4] = {
    {16,0,1,16},
    {0,1,16,0}
};
uint32_t e1[2][4] = {
    {1,0,16,1},
    {16,0,1,16}
};
uint32_t e2[4] = {0,16,1,0};
babykyber_encrypt(message, r, e1, e2, BABYKYBER_ENCRYPT_TRIGGER_ADDR);

// Decryption
uint32_t public_key[2][4][4];
uint32_t secret_key[2][4];
uint32_t ciphertext[2][2][4];
uint32_t decrypted_message, decrypted_value, m_b;
babykyber_decrypt(BABYKYBER_DECRYPT_TRIGGER_ADDR, public_key, secret_key, ciphertext,
                  &decrypted_message, &decrypted_value, &m_b);
```

## Hardware Interface

The accelerator is accessed via memory-mapped registers starting at `0x40007000`. The HAL layer handles all low-level register writes and reads.

## Cleaning

To clean the build outputs:

```bash
make clean
```

## License

[Add your license here]
