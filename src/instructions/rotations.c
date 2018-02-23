#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_rlca(t_cpustate *state)
{
  char			    bit = IS_NEG(state->a);

  state->a = (state->a << 1) | bit;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rla(t_cpustate *state)
{
  char			    bit = IS_NEG(state->a);

  state->a = (state->a << 1) | get_C(&state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->a);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrca(t_cpustate *state)
{
  char			    bit = (state->a & 1);

  state->a = (state->a >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->a);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rra(t_cpustate *state)
{
  char			    bit = (state->a & 1);

  state->a = (state->a >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->a);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}


