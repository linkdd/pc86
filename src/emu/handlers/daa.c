#include <emu/handlers/daa.h>

void daa (struct cpu_t *cpu, struct instruction_t *instruction)
{
     uint8_t old_al = cpu->registers.ax.byte.low;
     bool old_cf = cpu->registers.flags.bits.c;

     if (cpu->registers.ax.byte.low & 0xF > 9 || cpu->registers.flags.bits.a == 1)
     {
          uint16_t get_carry = cpu->registers.ax.byte.low + 6;
          cpu->registers.ax.byte.low = (int8_t) get_carry;

          cpu->registers.flags.bits.c = old_cf | (get_carry > UINT8_MAX);
          cpu->registers.flags.bits.a = 1;
     }
     else
     {
          cpu->registers.flags.bits.a = 0;
     }

     if (old_al > 0x99 || old_cf == 1)
     {
          cpu->registers.ax.byte.low += 0x60;
          cpu->registers.flags.bits.c = 1;
     }
     else
     {
          cpu->registers.flags.bits.c = 0;
     }

     cpu->registers.flags.bits.p = (word_bits_set (cpu->registers.ax.byte.low) % 2 == 0);
     cpu->registers.flags.bits.z = (cpu->registers.ax.byte.low == 0);
     cpu->registers.flags.bits.s = (word_bit_isset (cpu->registers.ax.byte.low, 0xF));
}
