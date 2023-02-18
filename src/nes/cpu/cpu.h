#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#define MEMORY_SIZE 0xFFFF

// struct definition of 6502 cpu for emulation
typedef struct cpu {
    uint8_t accumulator;
    uint8_t register_x;
    uint8_t register_y;
    uint16_t programCounter;
    uint8_t stackPointer;
    uint8_t status;

    uint8_t opcode;     // current opcode
    uint8_t cycles;     // cycles remaining for duration of current instruction
    uint8_t fetched;    // Latest fetched data
    uint16_t stkbase;   // Base address of stack >> 0x100 for 6502 cpu
    uint16_t abs_addr;  // Address of data to be accessed by intructions
    uint16_t rel_addr;  // Relative address resolutions
} cpu_t;

typedef enum {
    NONE,
    IRQ,
    NMI
} interrupt_t;

// Flags for each bit in the status register
typedef enum {
    flag_carry = (1 << 0),
    flag_zero = (1 << 1),
    flag_interrupt = (1 << 2),
    flag_decimal = (1 << 3),
    flag_brk = (1 << 4),
    flag_unused = (1 << 5),
    flag_overflow = (1 << 6),
    flag_negative = (1 << 7)
} flag_t;

// Addressing Mode
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

// FUNCTIONS
void cpu_init(cpu_t* cpu);
void cpu_debug(cpu_t* cpu);

void cpu_reset(cpu_t* cpu);
void cpu_clock(cpu_t* cpu);
void cpu_irk(cpu_t* cpu);
void cpu_nmi(cpu_t* cpu);

#endif