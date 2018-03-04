#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# define SWAP_NIBLES(a)		((((a) & 0x0F) << 4) | (((a) & 0xF0) >> 4))

# include "opts.h"
# include "cpu.h"

typedef int                 (t_ihandler)(struct s_game *game);

typedef struct              s_instruction
{
  const char                operation[0xff];
  t_ihandler                *handler;
  unsigned char             cycle_count;
  unsigned char             size;
}                           t_instruction;


extern t_instruction	    g_instructions[0xFF + 1];
extern t_instruction	    g_instructions_cb[0xFF + 1];

int                         unimplemented_instruction(t_game *game);
t_instruction               *decode_instruction(t_game *game, uint16_t pc);

t_ihandler                  i_prefix;
t_ihandler                  i_nop;
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
t_ihandler                  i_ld16_sp_hl;
t_ihandler                  i_ld16_hl_sp_n;
t_ihandler                  i_ld16_nn_sp;

/* PUSH */
t_ihandler                  i_push_af;
t_ihandler                  i_push_bc;
t_ihandler                  i_push_de;
t_ihandler                  i_push_hl;

/* Pop */
t_ihandler                  i_pop_af;
t_ihandler                  i_pop_bc;
t_ihandler                  i_pop_de;
t_ihandler                  i_pop_hl;

/* ALU 8 Bits */

/* ADD A, n */
t_ihandler                  i_add8_a_a    ;
t_ihandler                  i_add8_a_b    ;
t_ihandler                  i_add8_a_c    ;
t_ihandler                  i_add8_a_d    ;
t_ihandler                  i_add8_a_e    ;
t_ihandler                  i_add8_a_h    ;
t_ihandler                  i_add8_a_l    ;
t_ihandler                  i_add8_a_hl   ;
t_ihandler                  i_add8_a_sharp;

/* ADD SP, #*/
t_ihandler                  i_add_sp_sharp;

/* ADC A, n */
t_ihandler                  i_adc8_a_a    ;
t_ihandler                  i_adc8_a_b    ;
t_ihandler                  i_adc8_a_c    ;
t_ihandler                  i_adc8_a_d    ;
t_ihandler                  i_adc8_a_e    ;
t_ihandler                  i_adc8_a_h    ;
t_ihandler                  i_adc8_a_l    ;
t_ihandler                  i_adc8_a_hl   ;
t_ihandler                  i_adc8_a_sharp;

/* SUB A, n*/
t_ihandler                  i_sub8_a_a    ;
t_ihandler                  i_sub8_a_b    ;
t_ihandler                  i_sub8_a_c    ;
t_ihandler                  i_sub8_a_d    ;
t_ihandler                  i_sub8_a_e    ;
t_ihandler                  i_sub8_a_h    ;
t_ihandler                  i_sub8_a_l    ;
t_ihandler                  i_sub8_a_hl   ;
t_ihandler                  i_sub8_a_sharp;

/* SBC A, n*/
t_ihandler                  i_sbc8_a_a    ;
t_ihandler                  i_sbc8_a_b    ;
t_ihandler                  i_sbc8_a_c    ;
t_ihandler                  i_sbc8_a_d    ;
t_ihandler                  i_sbc8_a_e    ;
t_ihandler                  i_sbc8_a_h    ;
t_ihandler                  i_sbc8_a_l    ;
t_ihandler                  i_sbc8_a_hl   ;
t_ihandler                  i_sbc8_a_sharp;

/* INC n */
t_ihandler                  i_inc_a ;
t_ihandler                  i_inc_b ;
t_ihandler                  i_inc_c ;
t_ihandler                  i_inc_d ;
t_ihandler                  i_inc_e ;
t_ihandler                  i_inc_h ;
t_ihandler                  i_inc_l ;
t_ihandler                  i_inc_hl;

/* DEC n */
t_ihandler                  i_dec_a ;
t_ihandler                  i_dec_b ;
t_ihandler                  i_dec_c ;
t_ihandler                  i_dec_d ;
t_ihandler                  i_dec_e ;
t_ihandler                  i_dec_h ;
t_ihandler                  i_dec_l ;
t_ihandler                  i_dec_hl;

/* ALU 16 Bits */

t_ihandler                  i_add16_hl_bc;
t_ihandler                  i_add16_hl_de;
t_ihandler                  i_add16_hl_hl;
t_ihandler                  i_add16_hl_sp;

t_ihandler                  i_inc_d_bc;
t_ihandler                  i_inc_d_de;
t_ihandler                  i_inc_d_hl;
t_ihandler                  i_inc_d_sp;

t_ihandler                  i_dec_d_bc;
t_ihandler                  i_dec_d_de;
t_ihandler                  i_dec_d_hl;
t_ihandler                  i_dec_d_sp;

/* Jumps */
t_ihandler                  i_jp_nn;
t_ihandler                  i_jp_nz_nn;
t_ihandler                  i_jp_z_nn;
t_ihandler                  i_jp_nc_nn;
t_ihandler                  i_jp_c_nn;
t_ihandler                  i_jp_hl;
t_ihandler                  i_jp_n;
t_ihandler                  i_jr_nz_sharp;
t_ihandler                  i_jr_z_sharp ;
t_ihandler                  i_jr_nc_sharp;
t_ihandler                  i_jr_c_sharp ;

/* SRL */
t_ihandler                  i_srl_a ;
t_ihandler                  i_srl_b ;
t_ihandler                  i_srl_c ;
t_ihandler                  i_srl_d ;
t_ihandler                  i_srl_e ;
t_ihandler                  i_srl_h ;
t_ihandler                  i_srl_l ;
t_ihandler                  i_srl_hl;

/* xor */
t_ihandler                  i_xor_a    ;
t_ihandler                  i_xor_b    ;
t_ihandler                  i_xor_c    ;
t_ihandler                  i_xor_d    ;
t_ihandler                  i_xor_e    ;
t_ihandler                  i_xor_h    ;
t_ihandler                  i_xor_l    ;
t_ihandler                  i_xor_hl   ;
t_ihandler                  i_xor_sharp;

/* or */
t_ihandler                  i_or_a    ;
t_ihandler                  i_or_b    ;
t_ihandler                  i_or_c    ;
t_ihandler                  i_or_d    ;
t_ihandler                  i_or_e    ;
t_ihandler                  i_or_h    ;
t_ihandler                  i_or_l    ;
t_ihandler                  i_or_hl   ;
t_ihandler                  i_or_sharp;

/* and */
t_ihandler                  i_and_a    ;
t_ihandler                  i_and_b    ;
t_ihandler                  i_and_c    ;
t_ihandler                  i_and_d    ;
t_ihandler                  i_and_e    ;
t_ihandler                  i_and_h    ;
t_ihandler                  i_and_l    ;
t_ihandler                  i_and_hl   ;
t_ihandler                  i_and_sharp;

/* CP */
t_ihandler                  i_cp_a    ;
t_ihandler                  i_cp_b    ;
t_ihandler                  i_cp_c    ;
t_ihandler                  i_cp_d    ;
t_ihandler                  i_cp_e    ;
t_ihandler                  i_cp_h    ;
t_ihandler                  i_cp_l    ;
t_ihandler                  i_cp_hl   ;
t_ihandler                  i_cp_sharp;

/* BIT */

t_ihandler                  i_bit_a   ;
t_ihandler                  i_bit_b   ;
t_ihandler                  i_bit_c   ;
t_ihandler                  i_bit_d   ;
t_ihandler                  i_bit_e   ;
t_ihandler                  i_bit_h   ;
t_ihandler                  i_bit_l   ;
t_ihandler                  i_bit_hl   ;

/* SET */
t_ihandler                  i_set_a   ;
t_ihandler                  i_set_b   ;
t_ihandler                  i_set_c   ;
t_ihandler                  i_set_d   ;
t_ihandler                  i_set_e   ;
t_ihandler                  i_set_h   ;
t_ihandler                  i_set_l   ;
t_ihandler                  i_set_hl   ;

/* RES */
t_ihandler                  i_res_a   ;
t_ihandler                  i_res_b   ;
t_ihandler                  i_res_c   ;
t_ihandler                  i_res_d   ;
t_ihandler                  i_res_e   ;
t_ihandler                  i_res_h   ;
t_ihandler                  i_res_l   ;
t_ihandler                  i_res_hl   ;

/* Rotations */
t_ihandler                  i_rlca;
t_ihandler                  i_rla ;
t_ihandler                  i_rrca;
t_ihandler                  i_rra ;

/* CCF */
t_ihandler                  i_ccf;

/* DAA */
t_ihandler                  i_daa;

/* CPL */
t_ihandler                  i_cpl;

/* Calls */
t_ihandler                  i_call_nn;
t_ihandler                  i_call_nz_nn;
t_ihandler                  i_call_z_nn;
t_ihandler                  i_call_nc_nn;
t_ihandler                  i_call_c_nn;

/* RST */
t_ihandler                  i_rst_00;
t_ihandler                  i_rst_08;
t_ihandler                  i_rst_10;
t_ihandler                  i_rst_18;
t_ihandler                  i_rst_20;
t_ihandler                  i_rst_28;
t_ihandler                  i_rst_30;
t_ihandler                  i_rst_38;

/* RET */
t_ihandler                  i_ret;
t_ihandler                  i_ret_nz;
t_ihandler                  i_ret_z ;
t_ihandler                  i_ret_nc;
t_ihandler                  i_ret_c ;
t_ihandler                  i_reti ;

/* SWAP n */
t_ihandler                  i_swap_a ;
t_ihandler                  i_swap_b ;
t_ihandler                  i_swap_c ;
t_ihandler                  i_swap_d ;
t_ihandler                  i_swap_e ;
t_ihandler                  i_swap_h ;
t_ihandler                  i_swap_l ;
t_ihandler                  i_swap_hl;

/* RLC n */
t_ihandler                  i_rlc_a ;
t_ihandler                  i_rlc_b ;
t_ihandler                  i_rlc_c ;
t_ihandler                  i_rlc_d ;
t_ihandler                  i_rlc_e ;
t_ihandler                  i_rlc_h ;
t_ihandler                  i_rlc_l ;
t_ihandler                  i_rlc_hl;

/* RL n */
t_ihandler                  i_rl_a ;
t_ihandler                  i_rl_b ;
t_ihandler                  i_rl_c ;
t_ihandler                  i_rl_d ;
t_ihandler                  i_rl_e ;
t_ihandler                  i_rl_h ;
t_ihandler                  i_rl_l ;
t_ihandler                  i_rl_hl;

/* RRC n*/
t_ihandler                  i_rrc_a ;
t_ihandler                  i_rrc_b ;
t_ihandler                  i_rrc_c ;
t_ihandler                  i_rrc_d ;
t_ihandler                  i_rrc_e ;
t_ihandler                  i_rrc_h ;
t_ihandler                  i_rrc_l ;
t_ihandler                  i_rrc_hl;

/* RR n*/
t_ihandler                  i_rr_a ;
t_ihandler                  i_rr_b ;
t_ihandler                  i_rr_c ;
t_ihandler                  i_rr_d ;
t_ihandler                  i_rr_e ;
t_ihandler                  i_rr_h ;
t_ihandler                  i_rr_l ;
t_ihandler                  i_rr_hl;

/* SLA n */
t_ihandler                  i_sla_a ;
t_ihandler                  i_sla_b ;
t_ihandler                  i_sla_c ;
t_ihandler                  i_sla_d ;
t_ihandler                  i_sla_e ;
t_ihandler                  i_sla_h ;
t_ihandler                  i_sla_l ;
t_ihandler                  i_sla_hl;

/* SRA n */
t_ihandler                  i_sra_a ;
t_ihandler                  i_sra_b ;
t_ihandler                  i_sra_c ;
t_ihandler                  i_sra_d ;
t_ihandler                  i_sra_e ;
t_ihandler                  i_sra_h ;
t_ihandler                  i_sra_l ;
t_ihandler                  i_sra_hl;


/* HALT */
t_ihandler                  i_halt;

/* Stop */
t_ihandler                  i_stop;

/* DI */
t_ihandler                  i_di;

/* EI */
t_ihandler                  i_ei;

#endif /* !INSTRUCTIONS_H_ */

