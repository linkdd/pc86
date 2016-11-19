#include <emu/modrm.h>

static void *modrm_parse_memory_address (struct cpu_t *cpu, struct instruction_t *instruction)
{
     struct code_modrm_t *code = (struct code_modrm_t *) instruction->code;
     void *addr = NULL;

     switch (code->modrm.t.rm)
     {
          case 0: addr = (void *) (cpu->registers.bx.word + cpu->registers.si); break;
          case 1: addr = (void *) (cpu->registers.bx.word + cpu->registers.di); break;
          case 2: addr = (void *) (cpu->registers.bp + cpu->registers.si); break;
          case 3: addr = (void *) (cpu->registers.bp + cpu->registers.di); break;
          case 4: addr = (void *) (cpu->registers.si); break;
          case 5: addr = (void *) (cpu->registers.di); break;
          case 6: addr = (void *) (cpu->registers.bp); break;
          case 7: addr = (void *) (cpu->registers.bx.word); break;
     }

     return addr;
}

void modrm_parse (struct cpu_t *cpu,
                  struct instruction_t *instruction,
                  size_t size,
                  void **source,
                  void **dest)
{
     struct code_modrm_t *code = (struct code_modrm_t *) instruction->code;
     struct code_modrm_byte_t *codeb = (struct code_modrm_byte_t *) instruction->code;
     struct code_modrm_word_t *codew = (struct code_modrm_word_t *) instruction->code;
     void *registers[8];

     if (size == sizeof (int8_t))
     {
          registers[0] = &(cpu->registers.ax.byte.low);
          registers[1] = &(cpu->registers.cx.byte.low);
          registers[2] = &(cpu->registers.dx.byte.low);
          registers[3] = &(cpu->registers.bx.byte.low);
          registers[4] = &(cpu->registers.ax.byte.high);
          registers[5] = &(cpu->registers.cx.byte.high);
          registers[6] = &(cpu->registers.dx.byte.high);
          registers[7] = &(cpu->registers.bx.byte.high);
     }
     else if (size == sizeof (int16_t))
     {
          registers[0] = &(cpu->registers.ax.word);
          registers[1] = &(cpu->registers.cx.word);
          registers[2] = &(cpu->registers.dx.word);
          registers[3] = &(cpu->registers.bx.word);
          registers[4] = &(cpu->registers.sp);
          registers[5] = &(cpu->registers.bp);
          registers[6] = &(cpu->registers.si);
          registers[7] = &(cpu->registers.di);
     }

     switch (code->modrm.t.mod)
     {
          case 0:
               *source = modrm_parse_memory_address (cpu, instruction);
               *dest = registers[code->modrm.t.reg];
               break;

          case 1:
               instruction->size++;
               *source = modrm_parse_memory_address (cpu, instruction);
               *source += codeb->byte;
               *dest = registers[code->modrm.t.reg];
               break;

          case 2:
               instruction->size += 2;
               *source = modrm_parse_memory_address (cpu, instruction);
               *source += codew->word;
               *dest = registers[code->modrm.t.reg];
               break;

          case 3:
               *source = registers[code->modrm.t.rm];
               *dest = registers[code->modrm.t.reg];
               break;
     }
}
