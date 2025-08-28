#ifndef BABYKYBER_HAL_C
#define BABYKYBER_HAL_C

#include "babykyber_hal.h"
#include <stdint.h>

// Write a 32-bit value to a register
void babykyber_write_reg(uint32_t addr, uint32_t value) {
    *(volatile uint32_t *)addr = value;
}

// Read a 32-bit value from a register
uint32_t babykyber_read_reg(uint32_t addr) {
    return *(volatile uint32_t *)addr;
}

// Write an array of 32-bit values to consecutive registers
void babykyber_write_array(uint32_t base_addr, const uint32_t *data, uint32_t count) {
    for (uint32_t i = 0; i < count; ++i) {
        babykyber_write_reg(base_addr + i * 4, data[i]);
    }
}

// Read an array of 32-bit values from consecutive registers
void babykyber_read_array(uint32_t base_addr, uint32_t *data, uint32_t count) {
    for (uint32_t i = 0; i < count; ++i) {
        data[i] = babykyber_read_reg(base_addr + i * 4);
    }
}

#endif // BABYKYBER_HAL_C
