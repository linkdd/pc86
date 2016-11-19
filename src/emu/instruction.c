#include <emu/instruction.h>
#include <emu/handlers.h>

handler_t handlers[0xFF] =
{
     add_Eb_Gb,
     add_Ev_Gv,
     add_Gb_Eb,
     add_Gv_Ev,
     add_AL_Ib,
     add_AX_Iv,
     push_ES,
     pop_ES,

     or_Eb_Gb,
     or_Ev_Gv,
     or_Gb_Eb,
     or_Gv_Ev,
     or_AL_Ib,
     or_AX_Iv,
     push_CS,
     pop_CS,


     adc_Eb_Gb,
     adc_Ev_Gv,
     adc_Gb_Eb,
     adc_Gv_Ev,
     adc_AL_Ib,
     adc_AX_Iv,
     push_SS,
     pop_SS,

     sbb_Eb_Gb,
     sbb_Ev_Gv,
     sbb_Gb_Eb,
     sbb_Gv_Ev,
     sbb_AL_Ib,
     sbb_AX_Iv,
     push_DS,
     pop_DS
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
