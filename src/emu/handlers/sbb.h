#ifndef __SBB_H
#define __SBB_H

#include <emu/instruction.h>
#include <emu/modrm.h>
#include <emu/bits.h>

void sbb_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __SBB_H */