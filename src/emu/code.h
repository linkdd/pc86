#ifndef __OPCODE_H
#define __OPCODE_H

#include <emu/types.h>

struct code_t
{
     uint8_t opcode;
} __attribute__((packed));

struct code_modrm_t
{
     struct code_t _;

     union
     {
          struct modrm_t t;
          uint8_t b;
     } modrm;

} __attribute__((packed));

struct code_modrm_byte_t
{
     struct code_modrm_t _;

     uint8_t byte;
} __attribute__((packed));

struct code_modrm_word_t
{
     struct code_modrm_t _;

     uint16_t word;
} __attribute__((packed));

struct code_byte_t
{
     struct code_t _;

     uint8_t byte;
} __attribute__((packed));

struct code_word_t
{
     struct code_t _;

     uint16_t word;
} __attribute__((packed));

struct code_ext_t
{
     struct code_t _;

     uint8_t opcode_ext;
} __attribute__((packed));

#endif /* __OPCODE_H */