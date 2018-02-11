#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"


int                 i_ld8_b_n(t_cpustate *state)
{
  state->b = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_n(t_cpustate *state)
{
  state->c = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_n(t_cpustate *state)
{
  state->d = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_n(t_cpustate *state)
{
  state->e = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_n(t_cpustate *state)
{
  state->h = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_n(t_cpustate *state)
{
  state->l = state->op8;
  return RETURN_SUCCESS;
}

/* Register loads */


int                 i_ld8_a_a(t_cpustate *state)
{
  state->a = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_b(t_cpustate *state)
{
  state->a = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_c(t_cpustate *state)
{
  state->a = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_d(t_cpustate *state)
{
  state->a = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_e(t_cpustate *state)
{
  state->a = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_h(t_cpustate *state)
{
  state->a = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_l(t_cpustate *state)
{
  state->a = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_hl(t_cpustate *state)
{
  state->a = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_b_b(t_cpustate *state)
{
  state->b = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_c(t_cpustate *state)
{
  state->b = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_d(t_cpustate *state)
{
  state->b = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_e(t_cpustate *state)
{
  state->b = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_h(t_cpustate *state)
{
  state->b = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_l(t_cpustate *state)
{
  state->b = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_hl(t_cpustate *state)
{
  state->b = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_c_b(t_cpustate *state)
{
  state->c = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_c(t_cpustate *state)
{
  state->c = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_d(t_cpustate *state)
{
  state->c = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_e(t_cpustate *state)
{
  state->c = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_h(t_cpustate *state)
{
  state->c = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_l(t_cpustate *state)
{
  state->c = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_hl(t_cpustate *state)
{
  state->c = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_d_b(t_cpustate *state)
{
  state->d = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_c(t_cpustate *state)
{
  state->d = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_d(t_cpustate *state)
{
  state->d = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_e(t_cpustate *state)
{
  state->d = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_h(t_cpustate *state)
{
  state->d = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_l(t_cpustate *state)
{
  state->d = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_hl(t_cpustate *state)
{
  state->d = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_e_b(t_cpustate *state)
{
  state->e = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_c(t_cpustate *state)
{
  state->e = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_d(t_cpustate *state)
{
  state->e = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_e(t_cpustate *state)
{
  state->e = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_h(t_cpustate *state)
{
  state->e = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_l(t_cpustate *state)
{
  state->e = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_hl(t_cpustate *state)
{
  state->e = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_h_b(t_cpustate *state)
{
  state->h = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_c(t_cpustate *state)
{
  state->h = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_d(t_cpustate *state)
{
  state->h = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_e(t_cpustate *state)
{
  state->h = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_h(t_cpustate *state)
{
  state->h = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_l(t_cpustate *state)
{
  state->h = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_hl(t_cpustate *state)
{
  state->h = read_byte(state, get_hl(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_l_b(t_cpustate *state)
{
  state->l = state->b;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_c(t_cpustate *state)
{
  state->l = state->c;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_d(t_cpustate *state)
{
  state->l = state->d;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_e(t_cpustate *state)
{
  state->l = state->e;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_h(t_cpustate *state)
{
  state->l = state->h;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_l(t_cpustate *state)
{
  state->l = state->l;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_hl(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->l);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_b(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->b);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_c(t_cpustate *state)
{

  write_byte(state, get_hl(state), state->c);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_d(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->d);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_e(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->e);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_h(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->h);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_l(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->l);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_n(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->op8);
  return RETURN_SUCCESS;
}



int                 i_ld8_a_bc(t_cpustate *state)
{
  state->a = read_byte(state, get_bc(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_a_de(t_cpustate *state)
{
  state->a = read_byte(state, get_de(state));
  return RETURN_SUCCESS;
}

int                 i_ld8_a_nn(t_cpustate *state)
{
  state->a = read_byte(state, state->op16) ;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_sharp(t_cpustate *state)
{
  state->a = state->op8;
  return RETURN_SUCCESS;
}



int                 i_ld8_b_a(t_cpustate *state)
{
  state->b = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_a(t_cpustate *state)
{
  state->c = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_a(t_cpustate *state)
{
  state->d = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_a(t_cpustate *state)
{
  state->e = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_a(t_cpustate *state)
{
  state->h = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_a(t_cpustate *state)
{
  state->l = state->a;
  return RETURN_SUCCESS;
}

int                 i_ld8_bc_a(t_cpustate *state)
{
  write_byte(state, get_bc(state), state->a);
  return RETURN_SUCCESS;
}

int                 i_ld8_de_a(t_cpustate *state)
{
  write_byte(state, get_de(state), state->a);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_a(t_cpustate *state)
{

  write_byte(state, get_hl(state), state->a);
  return RETURN_SUCCESS;
}

int                 i_ld8_nn_a(t_cpustate *state)
{
  write_byte(state, state->op16, state->a);
  return RETURN_SUCCESS;
}

int                 i_ld8_a_cp(t_cpustate *state)
{

  state->a = read_byte(state, 0xFF00 + state->c);
  return RETURN_SUCCESS;
}

int                 i_ld8_cp_a(t_cpustate *state)
{
  write_byte(state, state->c + 0xFF00, state->a);
  return RETURN_SUCCESS;
}

int                 i_ldd8_a_hl(t_cpustate *state)
{
  state->a = read_byte(state, get_hl(state));
  dec_hl(state);
  return RETURN_SUCCESS;
}

int                 i_ldd8_hl_a(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->a);
  dec_hl(state);
  return RETURN_SUCCESS;
}

int                 i_ldi8_a_hl(t_cpustate *state)
{
  state->a = read_byte(state, get_hl(state));
  inc_hl(state);
  return RETURN_SUCCESS;
}

int                 i_ldi8_hl_a(t_cpustate *state)
{
  write_byte(state, get_hl(state), state->a);
  inc_hl(state);
  return RETURN_SUCCESS;
}

int                 i_ld_ff00_n_a(t_cpustate *state)
{
  write_byte(state, 0xFF00 + state->op8, state->a);
  return RETURN_SUCCESS;
}

int                 i_ld_a_ff00_n(t_cpustate *state)
{
  state->a = read_byte(state, 0xFF00 + state->op8);
  return RETURN_SUCCESS;
}
