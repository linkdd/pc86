#ifndef __POP_H
#define __POP_H

#include <emu/instruction.h>

void pop_ES (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_CS (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_SS (struct cpu_t *cpu, struct instruction_t *instruction);
void pop_DS (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __POP_H */