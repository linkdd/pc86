#ifndef __HANDLERS_H
#define __HANDLERS_H

#include <emu/instruction.h>
#include <emu/code.h>

void add_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void add_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void add_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void add_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);
void push_ES (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_ES (struct cpu_t *cpu, struct instruction_t *instruction);

void or_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void or_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void or_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void or_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);
void push_CS (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_CS (struct cpu_t *cpu, struct instruction_t *instruction);


void adc_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);
void push_SS (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_SS (struct cpu_t *cpu, struct instruction_t *instruction);

void sbb_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void sbb_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);
void push_DS (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_DS (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __HANDLERS_H */