#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "cpu.h"

#define MEMORY_SIZE 0xFFFF


typedef struct cpu {
    uint8_t accumulator;
    uint8_t register_x;
    uint8_t register_y;
    uint16_t programCounter;
    uint8_t stackPointer;
    uint8_t status;   
} cpu_t;

typedef enum {
    NONE,
    IRQ,
    NMI
} interrupt_t;

typedef enum {
    flag_carry,
    flag_zero,
    flag_interrupt,
    flag_decimal,
    flag_brk,
    flag_overflow,
    flag_negative
} flag_t;


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
