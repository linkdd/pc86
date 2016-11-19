#ifndef __CPU_H
#define __CPU_H

#include <emu/registers.h>

/*! \brief Structure used to manipulate the CPU */
struct cpu_t
{
     struct registers_t registers;        /*!< CPU registers */

     int8_t memory[0x10FFEF];  /*!< Segmented RAM from 0000h:0000h to FFFFh:FFFFh */
};

/*!
 * \brief Allocate a new CPU.
 *
 * \return A new CPU object
 */
struct cpu_t *cpu_new (void);

/*!
 * \brief Convert segment:offset address to physical address.
 */
void *cpu_address (struct cpu_t *cpu, int16_t segment, int16_t offset);

#endif /* __CPU_H */
