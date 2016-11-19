#ifndef __OR_H
#define __OR_H

#include <emu/instruction.h>
#include <emu/modrm.h>
#include <emu/bits.h>

void or_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void or_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void or_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __OR_H */