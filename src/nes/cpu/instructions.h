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

#endif