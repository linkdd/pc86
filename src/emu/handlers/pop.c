#include <emu/instruction.h>

void pop_ES (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     cpu->registers.sp += 2;
     cpu->registers.es = *addr;
}

void pop_CS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     cpu->registers.sp += 2;
     cpu->registers.es = *addr;
}

void pop_SS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     cpu->registers.sp += 2;
     cpu->registers.ss = *addr;
}

void pop_DS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     cpu->registers.sp += 2;
     cpu->registers.ds = *addr;
}
