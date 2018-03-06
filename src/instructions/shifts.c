#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"
#include "register.h"


int                 i_sla_a(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1);
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_b(t_game *game)
{
  char			    bit = IS_NEG(game->state.b);

  game->state.b = (game->state.b << 1);
  zero_flag_check(&game->state.f, game->state.b);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_c(t_game *game)
{
  char			    bit = IS_NEG(game->state.c);

  game->state.c = (game->state.c << 1);
  zero_flag_check(&game->state.f, game->state.c);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_d(t_game *game)
{
  char			    bit = IS_NEG(game->state.d);

  game->state.d = (game->state.d << 1);
  zero_flag_check(&game->state.f, game->state.d);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_e(t_game *game)
{
  char			    bit = IS_NEG(game->state.e);

  game->state.e = (game->state.e << 1);
  zero_flag_check(&game->state.f, game->state.e);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_h(t_game *game)
{
  char			    bit = IS_NEG(game->state.h);

  game->state.h = (game->state.h << 1);
  zero_flag_check(&game->state.f, game->state.h);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_l(t_game *game)
{
  char			    bit = IS_NEG(game->state.l);

  game->state.l = (game->state.l << 1);
  zero_flag_check(&game->state.f, game->state.l);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sla_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);
  char			    bit = IS_NEG(value);
  uint8_t           result = (value << 1);

  write_byte(game, game->state.hl, result);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_a(t_game *game)
{
  char			    bit = game->state.a & 1;

  game->state.a = (game->state.a >> 1) | (IS_NEG(game->state.a) << 7);
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_b(t_game *game)
{
  char			    bit = game->state.b & 1;

  game->state.b = (game->state.b >> 1) | (IS_NEG(game->state.b) << 7);
  zero_flag_check(&game->state.f, game->state.b);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_c(t_game *game)
{
  char			    bit = game->state.c & 1;

  game->state.c = (game->state.c >> 1) | (IS_NEG(game->state.c) << 7);
  zero_flag_check(&game->state.f, game->state.c);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_d(t_game *game)
{
  char			    bit = game->state.d & 1;

  game->state.d = (game->state.d >> 1) | (IS_NEG(game->state.d) << 7);
  zero_flag_check(&game->state.f, game->state.d);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_e(t_game *game)
{
  char			    bit = game->state.e & 1;

  game->state.e = (game->state.e >> 1) | (IS_NEG(game->state.e) << 7);
  zero_flag_check(&game->state.f, game->state.e);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_h(t_game *game)
{
  char			    bit = game->state.h & 1;

  game->state.h = (game->state.h >> 1) | (IS_NEG(game->state.h) << 7);
  zero_flag_check(&game->state.f, game->state.h);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_l(t_game *game)
{
  char			    bit = game->state.l & 1;

  game->state.l = (game->state.l >> 1) | (IS_NEG(game->state.l) << 7);
  zero_flag_check(&game->state.f, game->state.l);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_sra_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);
  char			    bit = value & 1;
  uint8_t           result = (value >> 1) | (IS_NEG(value) << 7);

  write_byte(game, game->state.hl, result);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}


int                 i_srl_a(t_game *game)
{
  char			    bit = game->state.a & 1;

  game->state.a = (game->state.a >> 1);
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_b(t_game *game)
{
  char			    bit = game->state.b & 1;

  game->state.b = (game->state.b >> 1);
  zero_flag_check(&game->state.f, game->state.b);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_c(t_game *game)
{
  char			    bit = game->state.c & 1;

  game->state.c = (game->state.c >> 1);
  zero_flag_check(&game->state.f, game->state.c);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_d(t_game *game)
{
  char			    bit = game->state.d & 1;

  game->state.d = (game->state.d >> 1);
  zero_flag_check(&game->state.f, game->state.d);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_e(t_game *game)
{
  char			    bit = game->state.e & 1;

  game->state.e = (game->state.e >> 1);
  zero_flag_check(&game->state.f, game->state.e);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_h(t_game *game)
{
  char			    bit = game->state.h & 1;

  game->state.h = (game->state.h >> 1);
  zero_flag_check(&game->state.f, game->state.h);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_l(t_game *game)
{
  char			    bit = game->state.l & 1;

  game->state.l = (game->state.l >> 1);
  zero_flag_check(&game->state.f, game->state.l);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_srl_hl(t_game *game)
{
  uint8_t           value = read_byte(game, game->state.hl);
  char			    bit = value & 1;
  uint8_t           result = value >> 1;

  write_byte(game, game->state.hl, result);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}
