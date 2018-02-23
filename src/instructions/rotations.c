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

  state->a = (state->a << 1) | get_C(&state->f);
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


int                 i_rlc_a(t_cpustate *state)
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

int                 i_rlc_b(t_cpustate *state)
{
  char			    bit = IS_NEG(state->b);

  state->b = (state->b << 1) | bit;
  zero_flag_check(&state->f, state->b);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_c(t_cpustate *state)
{
  char			    bit = IS_NEG(state->c);

  state->c = (state->c << 1) | bit;
  zero_flag_check(&state->f, state->c);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_d(t_cpustate *state)
{
  char			    bit = IS_NEG(state->d);

  state->d = (state->d << 1) | bit;
  zero_flag_check(&state->f, state->d);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_e(t_cpustate *state)
{
  char			    bit = IS_NEG(state->e);

  state->e = (state->e << 1) | bit;
  zero_flag_check(&state->f, state->e);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_h(t_cpustate *state)
{
  char			    bit = IS_NEG(state->h);

  state->h = (state->h << 1) | bit;
  zero_flag_check(&state->f, state->h);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_l(t_cpustate *state)
{
  char			    bit = IS_NEG(state->l);

  state->l = (state->l << 1) | bit;
  zero_flag_check(&state->f, state->l);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rlc_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = IS_NEG(value);
  uint8_t           result = 0;

  result = value << 1 | bit;
  write_byte(state, state->hl, value);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  reset_H(&state->f);
  if (bit)
    set_C(&state->f);
  else
    reset_C(&state->f);
  return RETURN_SUCCESS;
}






int                 i_rl_a(t_cpustate *state)
{
  char			    bit = IS_NEG(state->a);

  state->a = (state->a << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->a);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_b(t_cpustate *state)
{
  char			    bit = IS_NEG(state->c);

  state->b = (state->b << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->b);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_c(t_cpustate *state)
{
  char			    bit = IS_NEG(state->c);

  state->c = (state->c << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->c);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_d(t_cpustate *state)
{
  char			    bit = IS_NEG(state->d);

  state->d = (state->d << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->d);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_e(t_cpustate *state)
{
  char			    bit = IS_NEG(state->e);

  state->e = (state->e << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->e);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_h(t_cpustate *state)
{
  char			    bit = IS_NEG(state->h);

  state->h = (state->h << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->h);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_l(t_cpustate *state)
{
  char			    bit = IS_NEG(state->l);

  state->l = (state->l << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->l);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rl_hl(t_cpustate *state)
{
  char			    bit = IS_NEG(state->a);

  state->a = (state->a << 1) | get_C(&state->f);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->a);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}



int                 i_rrc_a(t_cpustate *state)
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

int                 i_rrc_b(t_cpustate *state)
{
  char			    bit = (state->b & 1);

  state->b = (state->b >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->b);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_c(t_cpustate *state)
{
  char			    bit = (state->c & 1);

  state->c = (state->c >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->c);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_d(t_cpustate *state)
{
  char			    bit = (state->d & 1);

  state->d = (state->d >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->d);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_e(t_cpustate *state)
{
  char			    bit = (state->e & 1);

  state->e = (state->e >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->e);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_h(t_cpustate *state)
{
  char			    bit = (state->h & 1);

  state->h = (state->h >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->h);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_l(t_cpustate *state)
{
  char			    bit = (state->l & 1);

  state->l = (state->l >> 1) | (bit << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->l);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rrc_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = (value & 1);
  uint8_t           result = (value >> 1) | (bit << 7);

  write_byte(state, state->hl, result);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, result);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}



int                 i_rr_a(t_cpustate *state)
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

int                 i_rr_b(t_cpustate *state)
{
  char			    bit = (state->b & 1);

  state->b = (state->b >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->b);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_c(t_cpustate *state)
{
  char			    bit = (state->c & 1);

  state->c = (state->c >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->c);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_d(t_cpustate *state)
{
  char			    bit = (state->d & 1);

  state->d = (state->d >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->d);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_e(t_cpustate *state)
{
  char			    bit = (state->e & 1);

  state->e = (state->e >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->e);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_h(t_cpustate *state)
{
  char			    bit = (state->h & 1);

  state->h = (state->h >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->h);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_l(t_cpustate *state)
{
  char			    bit = (state->l & 1);

  state->l = (state->l >> 1) | (get_C(&state->f) << 7);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, state->l);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_rr_hl(t_cpustate *state)
{
  uint8_t           value = read_byte(state, state->hl);
  char			    bit = (value & 1);
  uint8_t           result = (value >> 1) | (get_C(&state->f) << 7);

  write_byte(state, state->hl, result);
  reset_N(&state->f);
  reset_H(&state->f);
  zero_flag_check(&state->f, result);
  if (bit)
    set_C(&state->f);
  else 
    reset_C(&state->f);
  return RETURN_SUCCESS;
}
