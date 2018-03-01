#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

int                 i_and_a(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.a;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_b(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.b;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_c(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.c;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_d(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.d;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_e(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.e;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_h(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.h;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_l(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = game->state.l;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_hl(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint8_t           op2 = read_byte(&game->state, game->state.hl);

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_and_sharp(t_game *game)
{
  uint8_t           op1 = game->state.a;
  uint16_t          op2 = game->state.op8;

  game->state.a = op1 & op2;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}
