#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "cpu.h"

typedef struct cpu {
    uint8_t accumulator;
    uint8_t x;
    uint8_t y;
    uint16_t programCounter;
    uint8_t stackPointer;
    uint8_t status;
} cpu_t;

typedef enum {
    NONE = 0,
    // Indexed addressing
    ACCUMULATOR,
    IMMEDIATE,
    ZERO_PAGE,
    ABSOLUTE,
    RELATIVE,
    INDIRECT,
    //Other addressing
    ZERO_PAGE_X,
    ZERO_PAGE_Y,
    ABSOLUTE_X,
    ABSOLUTE_Y,
    INDIRECT_X,
    INDIRECT_Y,
    IMPLIED,
    IMPLIED_BRK
} addr_mode;
