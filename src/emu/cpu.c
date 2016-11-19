#include <stdlib.h>
#include <emu/cpu.h>
#include <emu/instruction.h>
#include <utils/log.h>

struct cpu_t *cpu_new (void)
{
     struct cpu_t *cpu = calloc (1, sizeof (struct cpu_t));

     if (cpu == NULL)
     {
          log (LOG_CRITICAL, "[cpu_new]: Can't allocate %lu bytes", sizeof (struct cpu_t));
          return NULL;
     }

     cpu->registers.flags.word = 0b0000000000001111;

     return cpu;
}

void *cpu_address (struct cpu_t *cpu, int16_t segment, int16_t offset)
{
     void *addr = NULL;

     if (cpu != NULL)
     {
          int32_t physical_addr = ((int32_t) segment) * 0x10 + offset;

          addr = &(cpu->memory[physical_addr]);
     }

     return addr;
}

void cpu_step (struct cpu_t *cpu)
{
     if (cpu != NULL)
     {
          void *opcode = cpu_address (cpu, cpu->registers.cs, cpu->registers.ip);
          struct instruction_t instruction;

          instruction_parse (&instruction, opcode);
          instruction.handler (cpu, &instruction);

          cpu->registers.ip += instruction.size;
     }
}
