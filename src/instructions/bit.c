#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_bit_a(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.a & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_b(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.b & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_c(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.a & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_d(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.d & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_e(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.e & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_h(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.h & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_l(t_game *game)
{
  zero_flag_check(&game->state.f, game->state.l & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_bit_hl(t_game *game)
{
  zero_flag_check(&game->state.f, read_byte(game, game->state.hl) & 0x80);
  reset_N(&game->state.f);
  set_H(&game->state.f);
  return RETURN_SUCCESS;
}




int                 i_set_a(t_game *game)
{
  game->state.a |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_b(t_game *game)
{
  game->state.b |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_c(t_game *game)
{
  game->state.c |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_d(t_game *game)
{
  game->state.d |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_e(t_game *game)
{
  game->state.e |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_h(t_game *game)
{
  game->state.h |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_l(t_game *game)
{
  game->state.l |= 1;
  return RETURN_SUCCESS;
}

int                 i_set_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);

  value |= 1;
  write_byte(game, game->state.hl, value);
  return RETURN_SUCCESS;
}


int                 i_res_a(t_game *game)
{
  game->state.a &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_b(t_game *game)
{
  game->state.b &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_c(t_game *game)
{
  game->state.c &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_d(t_game *game)
{
  game->state.d &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_e(t_game *game)
{
  game->state.e &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_h(t_game *game)
{
  game->state.h &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_l(t_game *game)
{
  game->state.l &= ~1; // keep only first 7 bits
  return RETURN_SUCCESS;
}

int                 i_res_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);

  value &= ~1; // keep only first 7 bits
  write_byte(game, game->state.hl, value);
  return RETURN_SUCCESS;
}
