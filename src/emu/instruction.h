#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#include <emu/cpu.h>
#include <emu/code.h>

struct instruction_t
{
     uint8_t size;
     struct code_t *code;
     void (*handler) (struct cpu_t *, struct instruction_t *);
};

typedef void (*handler_t) (struct cpu_t *, struct instruction_t *);

void instruction_parse (struct instruction_t *dest, void *opcode);

#endif /* __INSTRUCTION_H */