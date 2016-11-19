#ifndef __PUSH_H
#define __PUSH_H

#include <emu/instruction.h>

void push_ES (struct cpu_t *cpu, struct instruction_t *instruction);
void push_CS (struct cpu_t *cpu, struct instruction_t *instruction);
void push_SS (struct cpu_t *cpu, struct instruction_t *instruction);
void push_DS (struct cpu_t *cpu, struct instruction_t *instruction);

#endif /* __PUSH_H */