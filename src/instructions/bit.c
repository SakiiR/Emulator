#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_bit_a(t_cpustate *state)
{
  zero_flag_check(&state->f, state->a & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_b(t_cpustate *state)
{
  zero_flag_check(&state->f, state->b & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_c(t_cpustate *state)
{
  zero_flag_check(&state->f, state->a & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_d(t_cpustate *state)
{
  zero_flag_check(&state->f, state->d & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_e(t_cpustate *state)
{
  zero_flag_check(&state->f, state->e & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_h(t_cpustate *state)
{
  zero_flag_check(&state->f, state->h & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_l(t_cpustate *state)
{
  zero_flag_check(&state->f, state->l & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_hl(t_cpustate *state)
{
  zero_flag_check(&state->f, read_byte(state, state->hl) & 0x80);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}




int                 i_set_a(t_cpustate *state)
{
  state->a |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_b(t_cpustate *state)
{
  state->b |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_c(t_cpustate *state)
{
  state->c |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_d(t_cpustate *state)
{
  state->d |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_e(t_cpustate *state)
{
  state->e |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_h(t_cpustate *state)
{
  state->h |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_l(t_cpustate *state)
{
  state->l |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);

  value |= 1;
  write_byte(state, state->hl, value);
  return RETURN_SUCCESS;
}


int                 i_res_a(t_cpustate *state)
{
  state->a &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_b(t_cpustate *state)
{
  state->b &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_c(t_cpustate *state)
{
  state->c &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_d(t_cpustate *state)
{
  state->d &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_e(t_cpustate *state)
{
  state->e &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_h(t_cpustate *state)
{
  state->h &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_l(t_cpustate *state)
{
  state->l &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);

  value &= ~1; // keep only first 7 bits
  write_byte(state, state->hl, value);
  return RETURN_SUCCESS;
}
