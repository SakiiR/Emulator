#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"
#include "register.h"


int                 i_sla_a(t_cpustate *state)
{
  char			    bit = IS_NEG(state->a);

  state->a = (state->a << 1);
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_b(t_cpustate *state)
{
  char			    bit = IS_NEG(state->b);

  state->b = (state->b << 1);
  zero_flag_check(&state->f, state->b);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_c(t_cpustate *state)
{
  char			    bit = IS_NEG(state->c);

  state->c = (state->c << 1);
  zero_flag_check(&state->f, state->c);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_d(t_cpustate *state)
{
  char			    bit = IS_NEG(state->d);

  state->d = (state->d << 1);
  zero_flag_check(&state->f, state->d);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_e(t_cpustate *state)
{
  char			    bit = IS_NEG(state->e);

  state->e = (state->e << 1);
  zero_flag_check(&state->f, state->e);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_h(t_cpustate *state)
{
  char			    bit = IS_NEG(state->h);

  state->h = (state->h << 1);
  zero_flag_check(&state->f, state->h);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_l(t_cpustate *state)
{
  char			    bit = IS_NEG(state->l);

  state->l = (state->l << 1);
  zero_flag_check(&state->f, state->l);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sla_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = IS_NEG(value);
  uint8_t           result = (value << 1);

  write_byte(state, state->hl, result);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}



int                 i_sra_a(t_cpustate *state)
{
  char			    bit = state->a & 1;

  state->a = (state->a >> 1) | (IS_NEG(state->a) << 7);
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_b(t_cpustate *state)
{
  char			    bit = state->b & 1;

  state->b = (state->b >> 1) | (IS_NEG(state->b) << 7);
  zero_flag_check(&state->f, state->b);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_c(t_cpustate *state)
{
  char			    bit = state->c & 1;

  state->c = (state->c >> 1) | (IS_NEG(state->c) << 7);
  zero_flag_check(&state->f, state->c);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_d(t_cpustate *state)
{
  char			    bit = state->d & 1;

  state->d = (state->d >> 1) | (IS_NEG(state->d) << 7);
  zero_flag_check(&state->f, state->d);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_e(t_cpustate *state)
{
  char			    bit = state->e & 1;

  state->e = (state->e >> 1) | (IS_NEG(state->e) << 7);
  zero_flag_check(&state->f, state->e);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_h(t_cpustate *state)
{
  char			    bit = state->h & 1;

  state->h = (state->h >> 1) | (IS_NEG(state->h) << 7);
  zero_flag_check(&state->f, state->h);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_l(t_cpustate *state)
{
  char			    bit = state->l & 1;

  state->l = (state->l >> 1) | (IS_NEG(state->l) << 7);
  zero_flag_check(&state->f, state->l);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_sra_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = value & 1;
  uint8_t           result = (value >> 1) | (IS_NEG(value) << 7);

  write_byte(state, state->hl, result);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}


int                 i_srl_a(t_cpustate *state)
{
  char			    bit = state->a & 1;

  state->a = (state->a >> 1);
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_b(t_cpustate *state)
{
  char			    bit = state->b & 1;

  state->b = (state->b >> 1);
  zero_flag_check(&state->f, state->b);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_c(t_cpustate *state)
{
  char			    bit = state->c & 1;

  state->c = (state->c >> 1);
  zero_flag_check(&state->f, state->c);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_d(t_cpustate *state)
{
  char			    bit = state->d & 1;

  state->d = (state->d >> 1);
  zero_flag_check(&state->f, state->d);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_e(t_cpustate *state)
{
  char			    bit = state->e & 1;

  state->e = (state->e >> 1);
  zero_flag_check(&state->f, state->e);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_h(t_cpustate *state)
{
  char			    bit = state->h & 1;

  state->h = (state->h >> 1);
  zero_flag_check(&state->f, state->h);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_l(t_cpustate *state)
{
  char			    bit = state->l & 1;

  state->l = (state->l >> 1);
  zero_flag_check(&state->f, state->l);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_srl_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = value & 1;
  uint8_t           result = value >> 1;

  write_byte(state, state->hl, result);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}
