#ifndef __ADD_H
#define __ADD_H

#include <emu/instruction.h>
#include <emu/modrm.h>
#include <emu/bits.h>

void add_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void add_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void add_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __ADD_H */