#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

static uint8_t      get_bit(uint8_t value, uint8_t index)
{
  int               i = 0;

  while (value)     
  {
    if (i == index)
      return value & 1;
    value >>= 1;
    ++i;
  }
  return 0;
}

int                 i_bit_a(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->a, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_b(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->b, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_c(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->c, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_d(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->d, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_e(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->e, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_h(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->h, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_l(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(state->l, index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_bit_hl(t_cpustate *state)
{
  uint8_t           index = state->op8;

  if (get_bit(read_byte(state, state->hl), index) == 0)
    set_Z(&state->f);
  reset_N(&state->f);
  set_H(&state->f);
  return RETURN_SUCCESS;
}
