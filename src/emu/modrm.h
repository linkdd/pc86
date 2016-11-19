#ifndef __MODRM_H
#define __MODRM_H

#include <emu/instruction.h>

void modrm_parse (struct cpu_t *cpu,
                  struct instruction_t *instruction,
                  size_t size,
                  void **source,
                  void **dest);

#endif /* __MODRM_H */