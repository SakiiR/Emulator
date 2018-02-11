#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# define SWAP_NIBLES(a)		((((a) & 0x0F) << 4) | (((a) & 0xF0) >> 4))

# include "cpu.h"

typedef struct      s_instruction
{
  unsigned int      opcode;
  const char        operation[16];
  int               (*handler)(struct s_cpustate *state);
  unsigned char     cycle_count;
  unsigned char     size;
}                   t_instruction;


extern const t_instruction	g_instructions[0xFF + 1];

int                 unimplemented_instruction(t_cpustate *state);
int                 search_instruction(uint8_t opcode, t_cpustate *state);

/* Instructions handlers */
/* NOP */
int                 i_nop(t_cpustate *state);

/* Jumps */
int                 i_jp_nn(t_cpustate *state);

/* 8-bits Loads*/
/* LD nn,n */

/* 16-bits Loads */
/* LD n, nn*/

int                 i_ld16_bc_nn(t_cpustate *state); /* 0x01 */
int                 i_ld16_hl_nn(t_cpustate *state); /* 0x21 */

/* ALU */
int                 i_xor_a(t_cpustate *state);   /* 0xaf */

/* Restarts */
int                 i_rst_38(t_cpustate *state); /* 0xff */

#endif /* !INSTRUCTIONS_H_ */
