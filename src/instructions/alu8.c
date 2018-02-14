#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"
#include "memory.h"


int                         i_add8_a_a(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->a;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);

    return RETURN_SUCCESS;
}

int                         i_add8_a_b(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->b;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_c(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->c;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_d(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->d;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_e(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->e;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_h(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->h;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_l(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->l;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_hl(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = read_8(&state->memory.start[state->hl]);

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_add8_a_sharp(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->op8;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}


int                         i_adc8_a_a(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->a;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_b(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->b;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_c(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->c;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_d(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->d;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_e(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->e;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_h(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->h;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_l(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->l;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_hl(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = read_8(&state->memory.start[state->hl]);

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                         i_adc8_a_sharp(t_cpustate *state)
{
    const uint8_t           op1 = state->a;
    const uint8_t           op2 = state->op8;

    state->a = op1 + op2;

    /* flag check */
    carry_check(&state->f, op1, op2, state->a);
    half_carry_check(&state->f, op1, op2);
    reset_N(&state->f);
    zero_flag_check(&state->f, state->a);
    return RETURN_SUCCESS;
}

int                 i_inc_a(t_cpustate *state)
{
  const uint8_t     result = ++state->a;   


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}


int                 i_inc_b(t_cpustate *state)
{
  const uint8_t     result = ++state->b;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_c(t_cpustate *state)
{
  const uint8_t     result = ++state->c;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_d(t_cpustate *state)
{
  const uint8_t     result = ++state->d;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_e(t_cpustate *state)
{
  const uint8_t     result = ++state->e;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_h(t_cpustate *state)
{
  const uint8_t     result = ++state->h;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_l(t_cpustate *state)
{
  const uint8_t     result = ++state->l;


  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_inc_hl(t_cpustate *state)
{
  uint8_t           result = read_byte(state, state->hl);

  ++result;
  write_byte(state, state->hl, result);
  half_carry_check(&state->f, result - 1, 1);
  zero_flag_check(&state->f, result);
  reset_N(&state->f);
  return RETURN_SUCCESS;
}



int                 i_dec_a(t_cpustate *state)
{
  const uint8_t     result = --state->a;   

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}


int                 i_dec_b(t_cpustate *state)
{
  const uint8_t     result = --state->b;


  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_c(t_cpustate *state)
{
  const uint8_t     result = --state->c;

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_d(t_cpustate *state)
{
  const uint8_t     result = --state->d;

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_e(t_cpustate *state)
{
  const uint8_t     result = --state->e;

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_h(t_cpustate *state)
{
  const uint8_t     result = --state->h;

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_l(t_cpustate *state)
{
  const uint8_t     result = --state->l;

  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_hl(t_cpustate *state)
{
  uint8_t           result = read_byte(state, state->hl);

  --result;
  write_byte(state, state->hl, result);
  // TODO: Check For Borrow
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}
