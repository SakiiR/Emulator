#include "resource.h"
#include "cpu.h"
#include "register.h"
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

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}


int                 i_dec_b(t_cpustate *state)
{
  const uint8_t     result = --state->b;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_c(t_cpustate *state)
{
  const uint8_t     result = --state->c;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_d(t_cpustate *state)
{
  const uint8_t     result = --state->d;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_e(t_cpustate *state)
{
  const uint8_t     result = --state->e;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_h(t_cpustate *state)
{
  const uint8_t     result = --state->h;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_l(t_cpustate *state)
{
  const uint8_t     result = --state->l;

  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}

int                 i_dec_hl(t_cpustate *state)
{
  uint8_t           result = read_byte(state, state->hl);

  --result;
  write_byte(state, state->hl, result);
  check_no_borrow_half_carry(&state->f, result + 1, 1);
  zero_flag_check(&state->f, result);
  set_N(&state->f);
  return RETURN_SUCCESS;
}


int                 i_sub8_a_a(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->a;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_b(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->b;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_c(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->c;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_d(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->d;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_e(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->e;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_h(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->h;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_l(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->l;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_hl(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = read_byte(state, state->hl);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_sharp(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->op8;
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}



int                 i_sbc8_a_a(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->a + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_b(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->b + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_c(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->c + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_d(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->d + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_e(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->e + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_h(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->h + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_l(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->l + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_hl(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = read_byte(state, state->hl) + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_sharp(t_cpustate *state)
{
  uint8_t 			op1 = state->a;
  uint8_t 			op2 = state->op8 + get_C(&state->f);
  uint8_t 			res = op1 - op2;

  state->a = res;
  zero_flag_check(&state->f, res);
  set_N(&state->f);
  check_no_borrow_carry(&state->f, op1, op2);
  check_no_borrow_half_carry(&state->f, op1, op2);
  return RETURN_SUCCESS;
}
