#include "resource.h"
#include "game.h"
#include "cpu.h"
#include "register.h"
#include "memory_ar.h"
#include "memory.h"


int                         i_add8_a_a(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.a;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);

  return RETURN_SUCCESS;
}

int                         i_add8_a_b(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.b;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_c(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.c;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_d(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.d;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_e(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.e;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_h(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.h;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_l(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.l;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_hl(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = read_8(&game->state.memory.start[game->state.hl]);

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_add8_a_sharp(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.op8;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}


int                         i_adc8_a_a(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.a;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_b(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.b;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_c(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.c;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_d(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.d;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_e(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.e;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_h(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.h;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_l(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.l;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_hl(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = read_8(&game->state.memory.start[game->state.hl]);

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                         i_adc8_a_sharp(t_game *game)
{
  const uint8_t           op1 = game->state.a;
  const uint8_t           op2 = game->state.op8;

  game->state.a = op1 + op2;

  /* flag check */
  carry_check(&game->state.f, op1, op2, game->state.a);
  half_carry_check(&game->state.f, op1, op2);
  reset_N(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_inc_a(t_game *game)
{
  const uint8_t     result = ++game->state.a;   


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}


int                 i_inc_b(t_game *game)
{
  const uint8_t     result = ++game->state.b;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_c(t_game *game)
{
  const uint8_t     result = ++game->state.c;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_d(t_game *game)
{
  const uint8_t     result = ++game->state.d;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_e(t_game *game)
{
  const uint8_t     result = ++game->state.e;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_h(t_game *game)
{
  const uint8_t     result = ++game->state.h;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_l(t_game *game)
{
  const uint8_t     result = ++game->state.l;


  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_inc_hl(t_game *game)
{
  uint8_t           result = read_byte(&game->state, game->state.hl);

  ++result;
  write_byte(&game->state, game->state.hl, result);
  half_carry_check(&game->state.f, result - 1, 1);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  return RETURN_SUCCESS;
}



int                 i_dec_a(t_game *game)
{
  const uint8_t     result = --game->state.a;   

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}


int                 i_dec_b(t_game *game)
{
  const uint8_t     result = --game->state.b;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_c(t_game *game)
{
  const uint8_t     result = --game->state.c;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_d(t_game *game)
{
  const uint8_t     result = --game->state.d;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_e(t_game *game)
{
  const uint8_t     result = --game->state.e;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_h(t_game *game)
{
  const uint8_t     result = --game->state.h;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_l(t_game *game)
{
  const uint8_t     result = --game->state.l;

  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_dec_hl(t_game *game)
{
  uint8_t           result = read_byte(&game->state, game->state.hl);

  --result;
  write_byte(&game->state, game->state.hl, result);
  check_no_borrow_half_carry(&game->state.f, result + 1, 1);
  zero_flag_check(&game->state.f, result);
  set_N(&game->state.f);
  return RETURN_SUCCESS;
}


int                 i_sub8_a_a(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.a;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_b(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.b;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_c(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.c;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_d(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.d;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_e(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.e;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_h(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.h;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_l(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.l;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_hl(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = read_byte(&game->state, game->state.hl);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sub8_a_sharp(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.op8;
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}



int                 i_sbc8_a_a(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.a + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_b(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.b + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_c(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.c + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_d(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.d + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_e(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.e + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_h(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.h + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_l(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.l + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_hl(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = read_byte(&game->state, game->state.hl) + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_sbc8_a_sharp(t_game *game)
{
  uint8_t 			op1 = game->state.a;
  uint8_t 			op2 = game->state.op8 + get_C(&game->state.f);
  uint8_t 			res = op1 - op2;

  game->state.a = res;
  zero_flag_check(&game->state.f, res);
  set_N(&game->state.f);
  check_no_borrow_carry(&game->state.f, op1, op2);
  check_no_borrow_half_carry(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}

int                 i_add_sp_sharp(t_game *game)
{
  uint16_t          op1 = game->state.sp;
  uint8_t           op2 = game->state.op8;

  game->state.sp = op1 + op2;
  reset_Z(&game->state.f);
  reset_N(&game->state.f);
  carry_check(&game->state.f, op1, op2, game->state.sp);
  half_carry_check(&game->state.f, op1, op2);
  return RETURN_SUCCESS;
}
