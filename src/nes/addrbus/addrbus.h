#ifndef ADDRBUS_H
#define ADDRBUS_H
#include <stdint.h>
#include <stdlib.h>

#include "cpu.h"

typedef struct {
    cpu_t cpu;
    uint8_t ram[64 * 1024];
} addrbus_t

void write(uint16_t addr, uint8_t data);
uint8_t read(uint16_t addr, bool readOnly = false);

#endif