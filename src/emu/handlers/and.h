#ifndef __AND_H
#define __AND_H

#include <emu/instruction.h>
#include <emu/modrm.h>
#include <emu/bits.h>

void and_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void and_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void and_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void and_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void and_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void and_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __AND_H */