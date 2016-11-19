#include <emu/handlers/and.h>

void and_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint8_t *source = NULL;
     uint8_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint8_t), &source, &dest);

     *dest &= *source;

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (byte_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.z = (*dest == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (*dest, 0x7));
     cpu->registers.flags.bits.o = 0;
}

void and_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *source = NULL;
     uint16_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint16_t), &source, &dest);

     *dest &= *source;

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (word_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.z = (*dest == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (*dest, 0xF));
     cpu->registers.flags.bits.o = 0;
}

void and_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint8_t *source = NULL;
     uint8_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint8_t), &dest, &source);

     *dest &= *source;

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (byte_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.z = (*dest == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (*dest, 0x7));
     cpu->registers.flags.bits.o = 0;
}

void and_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t *source = NULL;
     uint16_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint16_t), &dest, &source);

     *dest &= *source;

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (word_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.z = (*dest == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (*dest, 0xF));
     cpu->registers.flags.bits.o = 0;
}

void and_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction)
{
     instruction->size++;
     cpu->registers.ax.byte.low &= *((uint8_t *) instruction->code + 1);

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (byte_bits_set (cpu->registers.ax.byte.low) % 2 == 0);
     cpu->registers.flags.bits.z = (cpu->registers.ax.byte.low == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (cpu->registers.ax.byte.low, 0x7));
     cpu->registers.flags.bits.o = 0;
}

void and_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction)
{
     instruction->size += 2;
     cpu->registers.ax.word &= *((uint16_t *) instruction->code + 1);

     cpu->registers.flags.bits.c = 0;
     cpu->registers.flags.bits.p = (word_bits_set (cpu->registers.ax.word) % 2 == 0);
     cpu->registers.flags.bits.z = (cpu->registers.ax.word == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (cpu->registers.ax.word, 0xF));
     cpu->registers.flags.bits.o = 0;
}