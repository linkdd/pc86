#include <emu/instruction.h>
#include <emu/handlers/all.h>

handler_t handlers[0xFF] =
{
     /* 0, 0 -> 7 */
     add_Eb_Gb,
     add_Ev_Gv,
     add_Gb_Eb,
     add_Gv_Ev,
     add_AL_Ib,
     add_AX_Iv,
     push_ES,
     pop_ES,

     /* 0, 8 -> F */
     or_Eb_Gb,
     or_Ev_Gv,
     or_Gb_Eb,
     or_Gv_Ev,
     or_AL_Ib,
     or_AX_Iv,
     push_CS,
     pop_CS,

     /* 1, 0 -> 7 */
     adc_Eb_Gb,
     adc_Ev_Gv,
     adc_Gb_Eb,
     adc_Gv_Ev,
     adc_AL_Ib,
     adc_AX_Iv,
     push_SS,
     pop_SS,

     /* 1, 8 -> F */
     sbb_Eb_Gb,
     sbb_Ev_Gv,
     sbb_Gb_Eb,
     sbb_Gv_Ev,
     sbb_AL_Ib,
     sbb_AX_Iv,
     push_DS,
     pop_DS,

     /* 2, 0 -> 7 */
     and_Eb_Gb,
     and_Ev_Gv,
     and_Gb_Eb,
     and_Gv_Ev,
     and_AL_Ib,
     and_AX_Iv,
     NULL,
     daa
};

void instruction_parse (struct instruction_t *dest, void *opcode)
{
     if (dest != NULL && opcode != NULL)
     {
          dest->code = (struct code_t *) opcode;
          dest->handler = handlers[dest->code->opcode];
          dest->size = 1;
     }
}
