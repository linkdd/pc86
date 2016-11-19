#include <emu/handlers/push.h>

void push_ES (struct cpu_t *cpu, struct instruction_t *instruction)
{
     cpu->registers.sp -= 2;
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     *addr = cpu->registers.es;
}

void push_CS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     cpu->registers.sp -= 2;
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     *addr = cpu->registers.es;
}

void push_SS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     cpu->registers.sp -= 2;
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     *addr = cpu->registers.ss;
}

void push_DS (struct cpu_t *cpu, struct instruction_t *instruction)
{
     cpu->registers.sp -= 2;
     uint16_t *addr = cpu_address (cpu, cpu->registers.ss, cpu->registers.sp);
     *addr = cpu->registers.ds;
}
