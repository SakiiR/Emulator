#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

#define SWAP_N(n) (n = ((n & 0x0F) << 4 | (n & 0xF0) >> 4 ))

int                 i_swap_a(t_game *game)
{
  SWAP_N(game->state.a);
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_b(t_game *game)
{
  SWAP_N(game->state.b);
  zero_flag_check(&game->state.f, game->state.b);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_c(t_game *game)
{
  SWAP_N(game->state.c);
  zero_flag_check(&game->state.f, game->state.c);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_d(t_game *game)
{
  SWAP_N(game->state.d);
  zero_flag_check(&game->state.f, game->state.d);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_e(t_game *game)
{
  SWAP_N(game->state.e);
  zero_flag_check(&game->state.f, game->state.e);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_h(t_game *game)
{
  SWAP_N(game->state.h);
  zero_flag_check(&game->state.f, game->state.h);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_l(t_game *game)
{
  SWAP_N(game->state.l);
  zero_flag_check(&game->state.f, game->state.l);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_swap_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);

  SWAP_N(value);
  zero_flag_check(&game->state.f, value);
  write_byte(game, game->state.hl, value);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  reset_C(&game->state.f);
  return RETURN_SUCCESS;
}
