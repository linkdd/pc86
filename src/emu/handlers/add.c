#include <emu/handlers/add.h>

void add_Eb_Gb (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t result = 0;
     uint8_t *source = NULL;
     uint8_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint8_t), &source, &dest);

     result = *dest + *source;
     *dest = (uint8_t) result;

     cpu->registers.flags.bits.c = (result > UINT8_MAX);
     cpu->registers.flags.bits.p = (byte_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (*dest, 0x7));
     cpu->registers.flags.bits.o = (result > UINT8_MAX);
}

void add_Ev_Gv (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint32_t result = 0;
     uint16_t *source = NULL;
     uint16_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint16_t), &source, &dest);

     result = *dest + *source;
     *dest = (uint16_t) result;

     cpu->registers.flags.bits.c = (result > UINT16_MAX);
     cpu->registers.flags.bits.p = (word_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (*dest, 0xF));
     cpu->registers.flags.bits.o = (result > UINT16_MAX);
}

void add_Gb_Eb (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint16_t result = 0;
     uint8_t *source = NULL;
     uint8_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint8_t), &dest, &source);

     result = *dest + *source;
     *dest = (uint8_t) result;

     cpu->registers.flags.bits.c = (result > UINT8_MAX);
     cpu->registers.flags.bits.p = (byte_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (*dest, 0x7));
     cpu->registers.flags.bits.o = (result > UINT8_MAX);
}

void add_Gv_Ev (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint32_t result = 0;
     uint16_t *source = NULL;
     uint16_t *dest = NULL;

     instruction->size++;
     modrm_parse (cpu, instruction, sizeof (uint16_t), &dest, &source);

     result = *dest + *source;
     *dest = (uint16_t) result;

     cpu->registers.flags.bits.c = (result > UINT16_MAX);
     cpu->registers.flags.bits.p = (word_bits_set (*dest) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (*dest, 0xF));
     cpu->registers.flags.bits.o = (result > UINT16_MAX);
}

void add_AL_Ib (struct cpu_t *cpu, struct instruction_t *instruction)
{
     struct code_byte_t *code = (struct code_byte_t *) instruction->code;
     uint16_t result = 0;

     instruction->size++;

     result = cpu->registers.ax.byte.low + code->byte;
     cpu->registers.ax.byte.low = (uint8_t) result;

     cpu->registers.flags.bits.c = (result > UINT8_MAX);
     cpu->registers.flags.bits.p = (byte_bits_set (cpu->registers.ax.byte.low) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (byte_bit_isset (cpu->registers.ax.byte.low, 0x7));
     cpu->registers.flags.bits.o = (result > UINT8_MAX);
}

void add_AX_Iv (struct cpu_t *cpu, struct instruction_t *instruction)
{
     struct code_word_t *code = (struct code_word_t *) instruction->code;
     uint16_t result = 0;

     instruction->size += 2;

     result = cpu->registers.ax.word + code->word;
     cpu->registers.ax.word = (uint16_t) result;

     cpu->registers.flags.bits.c = (result > UINT16_MAX);
     cpu->registers.flags.bits.p = (word_bits_set (cpu->registers.ax.word) % 2 == 0);
     cpu->registers.flags.bits.a = (result > 0xF);
     cpu->registers.flags.bits.z = (result == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (cpu->registers.ax.word, 0xF));
     cpu->registers.flags.bits.o = (result > UINT16_MAX);
}