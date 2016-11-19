#include <emu/bits.h>

bool byte_bit_isset (uint8_t byte, int bit)
{
     return byte & (1 << bit);
}

bool word_bit_isset (uint16_t word, int bit)
{
     return word & (1 << bit);
}

size_t byte_bits_set (uint8_t byte)
{
     size_t result = 0;
     int i;

     for (i = 0; i < 8; ++i)
     {
          if (byte_bit_isset (byte, i))
          {
               result++;
          }
     }

     return result;
}

size_t word_bits_set (uint16_t word)
{
     size_t result = 0;
     int i;

     for (i = 0; i < 16; ++i)
     {
          if (word_bit_isset (word, i))
          {
               result++;
          }
     }

     return result;
}
