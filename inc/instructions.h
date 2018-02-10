#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# include "cpu.h"

typedef struct      s_instruction
{
  unsigned int      opcode;
  int               (*handler)(struct s_cpustate *state);
}                   t_instruction;

int                 unimplemented_instruction(t_cpustate *state);
int                 search_instruction(uint8_t opcode, t_cpustate *state);

/* Instructions handlers */
/* NOP */
int                 instruction_nop(t_cpustate *state);

/* Jumps */
int                 instruction_jp_nn(t_cpustate *state);

/* 8-bits Loads*/
/* LD nn,n */

/* 16-bits Loads */
/* LD n, nn*/

int                 instruction_ld16_bc_nn(t_cpustate *state); /* 0x01 */
int                 instruction_ld16_hl_nn(t_cpustate *state); /* 0x21 */

/* ALU */
int                 instruction_xor_a(t_cpustate *state);   /* 0xaf */

/* Restarts */
int                 instruction_rst_38(t_cpustate *state); /* 0xff */

#endif /* !INSTRUCTIONS_H_ */
