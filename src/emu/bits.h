#ifndef __BITS_H
#define __BITS_H

#include <emu/types.h>

bool byte_bit_isset (uint8_t byte, int bit);
bool word_bit_isset (uint16_t word, int bit);

size_t byte_bits_set (uint8_t byte);
size_t word_bits_set (uint16_t word);

#endif /* __BITS_H */