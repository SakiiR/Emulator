#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

#define SWAP_N(n) (n = ((n & 0x0F) << 4 | (n & 0xF0) >> 4 ))

int                 i_swap_a(t_cpustate *state)
{
  SWAP_N(state->a);
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_b(t_cpustate *state)
{
  SWAP_N(state->b);
  zero_flag_check(&state->f, state->b);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_c(t_cpustate *state)
{
  SWAP_N(state->c);
  zero_flag_check(&state->f, state->c);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_d(t_cpustate *state)
{
  SWAP_N(state->d);
  zero_flag_check(&state->f, state->d);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_e(t_cpustate *state)
{
  SWAP_N(state->e);
  zero_flag_check(&state->f, state->e);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_h(t_cpustate *state)
{
  SWAP_N(state->h);
  zero_flag_check(&state->f, state->h);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_l(t_cpustate *state)
{
  SWAP_N(state->l);
  zero_flag_check(&state->f, state->l);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_swap_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);

  SWAP_N(value);
  zero_flag_check(&state->f, value);
  write_byte(state, state->hl, value);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}
