#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# define SWAP_NIBLES(a)		((((a) & 0x0F) << 4) | (((a) & 0xF0) >> 4))

# include "cpu.h"

typedef int                 (t_ihandler)(struct s_cpustate *state);

typedef struct              s_instruction
{
  const char                operation[0xff];
  t_ihandler                *handler;
  unsigned char             cycle_count;
  unsigned char             size;
}                           t_instruction;


extern const t_instruction	g_instructions[0xFF + 1];

int                         unimplemented_instruction(t_cpustate *state);
int                         search_instruction(uint8_t opcode, t_cpustate *state);

t_ihandler                  i_nop;
t_ihandler                  i_ld16_bc_nn;
t_ihandler                  i_ld16_hl_nn;
t_ihandler                  i_xor_a;
t_ihandler                  i_rst_38;

t_ihandler                  i_ld8_b_n;
t_ihandler                  i_ld8_c_n;
t_ihandler                  i_ld8_d_n;
t_ihandler                  i_ld8_e_n;
t_ihandler                  i_ld8_h_n;
t_ihandler                  i_ld8_l_n;

/* Jumps */
t_ihandler                  i_jp_nn;
t_ihandler                  i_jp_nz_nn;
t_ihandler                  i_jp_z_nn;
t_ihandler                  i_jp_nc_nn;
t_ihandler                  i_jp_c_nn;

#endif /* !INSTRUCTIONS_H_ */

