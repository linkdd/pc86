#ifndef __ADC_H
#define __ADC_H

#include <emu/instruction.h>
#include <emu/modrm.h>
#include <emu/bits.h>

void adc_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction);
void adc_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __ADC_H */