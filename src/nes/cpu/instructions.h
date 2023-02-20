#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>
#include "cpu.h"

// Instruction opcodes
typedef enum {
    ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI,
    BNE, BPL, BRK, BVC, BVS, CLC, CLD, CLI,
    CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR,
    INC, INX, INY, JMP, JSR, LDA, LDX, LDY,
    LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL,
    ROR, RTI, RTS, SBC, SEC, SED, SEI, STA,
    STX, STY, TAX, TAY, TSX, TXA, TXS, TYA,
} instr;


typedef struct {
    const char *instr_name;     // instruction name
    const char *addrm_type;     // Address mode name
    bool pg_cross_cycle;    // Extra cycle on page cross?
    uint8_t opcode;     // opcode byte
    uint8_t cycles;     // Base cycles
    instr instruction;  // Instruction type
    addr_mode addrm;    // Addressing mode enum
}opcode;

// Macro for opcode definition list to condense raw definition
// macro: OP(0x11, ORA, INDIRECT, 5, *)
// raw: /* 0x11 */ {"ORA", "INDIRECT_Y", true, 5, instr::ORA, addr_mode::INDIRECT_Y,}

// general definition for any function name
#define _VFUNC_(name, n) name##n
#define _VFUNC(name, n) _VFUNC_(name, n)
#define VFUNC(func, ...) _VFUNC(func, __NARG__(__VA_ARGS__)) (__VA_ARGS__)
#define OP(...) VFUNC(OP, __VA_ARGS__)

// Invalid opcode
#define OP1(opcode) \
    {"KIL", "----", false, opcode, 0, instr:: ins, addr_mode:: addrm}

// Standard opcode
#define OP4(opcode) \
    {#ins, #addrm, false, opcode, 0, instr:: ins, addr_mode:: addrm}

// Opcode with extra cycle across pages
#define OP5(opcode) \
    {#ins, #addrm, true, opcode, 0, instr:: ins, addr_mode:: addrm}

// Add opcode lookup table
#endif