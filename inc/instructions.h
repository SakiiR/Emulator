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
extern const t_instruction	g_instructions_cb[0xFF + 1];

int                         unimplemented_instruction(t_cpustate *state);
int                         search_instruction(uint8_t opcode, t_cpustate *state);

t_ihandler                  i_prefix;
t_ihandler                  i_nop;
t_ihandler                  i_xor_a;
t_ihandler                  i_rst_38;

/* 8 bits loads */
/* LD nn, n*/
t_ihandler                  i_ld8_b_n;
t_ihandler                  i_ld8_c_n;
t_ihandler                  i_ld8_d_n;
t_ihandler                  i_ld8_e_n;
t_ihandler                  i_ld8_h_n;
t_ihandler                  i_ld8_l_n;

/* LD r1, r2 */
t_ihandler                  i_ld8_a_a ;
t_ihandler                  i_ld8_a_b ;
t_ihandler                  i_ld8_a_c ;
t_ihandler                  i_ld8_a_d ;
t_ihandler                  i_ld8_a_e ;
t_ihandler                  i_ld8_a_h ;
t_ihandler                  i_ld8_a_l ;
t_ihandler                  i_ld8_a_hl;
t_ihandler                  i_ld8_b_b ;
t_ihandler                  i_ld8_b_c ;
t_ihandler                  i_ld8_b_d ;
t_ihandler                  i_ld8_b_e ;
t_ihandler                  i_ld8_b_h ;
t_ihandler                  i_ld8_b_l ;
t_ihandler                  i_ld8_b_hl;
t_ihandler                  i_ld8_c_b ;
t_ihandler                  i_ld8_c_c ;
t_ihandler                  i_ld8_c_d ;
t_ihandler                  i_ld8_c_e ;
t_ihandler                  i_ld8_c_h ;
t_ihandler                  i_ld8_c_l ;
t_ihandler                  i_ld8_c_hl;
t_ihandler                  i_ld8_d_b ;
t_ihandler                  i_ld8_d_c ;
t_ihandler                  i_ld8_d_d ;
t_ihandler                  i_ld8_d_e ;
t_ihandler                  i_ld8_d_h ;
t_ihandler                  i_ld8_d_l ;
t_ihandler                  i_ld8_d_hl;
t_ihandler                  i_ld8_e_b ;
t_ihandler                  i_ld8_e_c ;
t_ihandler                  i_ld8_e_d ;
t_ihandler                  i_ld8_e_e ;
t_ihandler                  i_ld8_e_h ;
t_ihandler                  i_ld8_e_l ;
t_ihandler                  i_ld8_e_hl;
t_ihandler                  i_ld8_h_b ;
t_ihandler                  i_ld8_h_c ;
t_ihandler                  i_ld8_h_d ;
t_ihandler                  i_ld8_h_e ;
t_ihandler                  i_ld8_h_h ;
t_ihandler                  i_ld8_h_l ;
t_ihandler                  i_ld8_h_hl;
t_ihandler                  i_ld8_l_b ;
t_ihandler                  i_ld8_l_c ;
t_ihandler                  i_ld8_l_d ;
t_ihandler                  i_ld8_l_e ;
t_ihandler                  i_ld8_l_h ;
t_ihandler                  i_ld8_l_l ;
t_ihandler                  i_ld8_l_hl;
t_ihandler                  i_ld8_hl_b;
t_ihandler                  i_ld8_hl_c;
t_ihandler                  i_ld8_hl_d;
t_ihandler                  i_ld8_hl_e;
t_ihandler                  i_ld8_hl_h;
t_ihandler                  i_ld8_hl_l;
t_ihandler                  i_ld8_hl_n;

/* LD A, n */
t_ihandler                  i_ld8_a_bc   ;
t_ihandler                  i_ld8_a_de   ;
t_ihandler                  i_ld8_a_nn   ;
t_ihandler                  i_ld8_a_sharp;

/* LD n, A*/
t_ihandler                  i_ld8_b_a ;
t_ihandler                  i_ld8_c_a ;
t_ihandler                  i_ld8_d_a ;
t_ihandler                  i_ld8_e_a ;
t_ihandler                  i_ld8_h_a ;
t_ihandler                  i_ld8_l_a ;
t_ihandler                  i_ld8_bc_a;
t_ihandler                  i_ld8_de_a;
t_ihandler                  i_ld8_hl_a;
t_ihandler                  i_ld8_nn_a;

/* LD A, (C)*/
t_ihandler                  i_ld8_a_cp;

/* LD (C), A*/
t_ihandler                  i_ld8_cp_a;

/* LDD A, (HL)*/
t_ihandler                  i_ldd8_a_hl;

/* LDD (HL), A*/
t_ihandler                  i_ldd8_hl_a;

/* LDI A, (HL) */
t_ihandler                  i_ldi8_a_hl;

/* LDI (HL), A */
t_ihandler                  i_ldi8_hl_a;

/* LD ($FF00 + n), A */
t_ihandler                  i_ld_ff00_n_a;
/* LD A, ($FF00 + n) */
t_ihandler                  i_ld_a_ff00_n;

/* 16 bits loads */
t_ihandler                  i_ld16_bc_nn;
t_ihandler                  i_ld16_de_nn;
t_ihandler                  i_ld16_sp_nn;
t_ihandler                  i_ld16_hl_nn;

/* Jumps */
t_ihandler                  i_jp_nn;
t_ihandler                  i_jp_nz_nn;
t_ihandler                  i_jp_z_nn;
t_ihandler                  i_jp_nc_nn;
t_ihandler                  i_jp_c_nn;

/* SRL */
t_ihandler                  i_srl_a ;
t_ihandler                  i_srl_b ;
t_ihandler                  i_srl_c ;
t_ihandler                  i_srl_d ;
t_ihandler                  i_srl_e ;
t_ihandler                  i_srl_h ;
t_ihandler                  i_srl_l ;
t_ihandler                  i_srl_hl;

/* CCF */
t_ihandler                  i_ccf;

/* Calls */
t_ihandler                  i_call_nn;

/* HALT */
t_ihandler                  i_halt;

/* Stop */
t_ihandler                  i_stop;

#endif /* !INSTRUCTIONS_H_ */

