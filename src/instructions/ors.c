#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int                 i_or_a(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->a;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_b(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->b;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_c(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->c;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_d(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->d;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_e(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->e;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_h(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->h;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_l(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = state->l;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_hl(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint8_t           op2 = read_byte(state, state->hl);

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_or_sharp(t_cpustate *state)
{
  uint8_t           op1 = state->a;
  uint16_t          op2 = state->op8;

  state->a = op1 | op2;
  zero_flag_check(&state->f, state->a);
  reset_N(&state->f);
  reset_H(&state->f);
  reset_C(&state->f);
  return RETURN_SUCCESS;
}
