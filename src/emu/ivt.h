#ifndef __IVT_H
#define __IVT_H

#include <emu/types.h>

/*! Interrupt Vector Table */
struct ivt_t
{
     int32_t jump_table[0xFF]; /*!< Table of SECTOR:OFFSET addresses */
} __attribute__((packed));

#endif /* __IVT_H */
