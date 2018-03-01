#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_rlca(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1) | bit;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rla(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrca(t_game *game)
{
  char			    bit = (game->state.a & 1);

  game->state.a = (game->state.a >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rra(t_game *game)
{
  char			    bit = (game->state.a & 1);

  game->state.a = (game->state.a >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}


int                 i_rlc_a(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1) | bit;
  zero_flag_check(&game->state.f, game->state.a);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_b(t_game *game)
{
  char			    bit = IS_NEG(game->state.b);

  game->state.b = (game->state.b << 1) | bit;
  zero_flag_check(&game->state.f, game->state.b);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_c(t_game *game)
{
  char			    bit = IS_NEG(game->state.c);

  game->state.c = (game->state.c << 1) | bit;
  zero_flag_check(&game->state.f, game->state.c);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_d(t_game *game)
{
  char			    bit = IS_NEG(game->state.d);

  game->state.d = (game->state.d << 1) | bit;
  zero_flag_check(&game->state.f, game->state.d);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_e(t_game *game)
{
  char			    bit = IS_NEG(game->state.e);

  game->state.e = (game->state.e << 1) | bit;
  zero_flag_check(&game->state.f, game->state.e);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_h(t_game *game)
{
  char			    bit = IS_NEG(game->state.h);

  game->state.h = (game->state.h << 1) | bit;
  zero_flag_check(&game->state.f, game->state.h);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_l(t_game *game)
{
  char			    bit = IS_NEG(game->state.l);

  game->state.l = (game->state.l << 1) | bit;
  zero_flag_check(&game->state.f, game->state.l);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rlc_hl(t_game *game)
{
  uint8_t           value = read_byte(&game->state, game->state.hl);
  char			    bit = IS_NEG(value);
  uint8_t           result = 0;

  result = value << 1 | bit;
  write_byte(&game->state, game->state.hl, value);
  zero_flag_check(&game->state.f, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  if (bit)
    set_C(&game->state.f);
  else
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}






int                 i_rl_a(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_b(t_game *game)
{
  char			    bit = IS_NEG(game->state.c);

  game->state.b = (game->state.b << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.b);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_c(t_game *game)
{
  char			    bit = IS_NEG(game->state.c);

  game->state.c = (game->state.c << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.c);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_d(t_game *game)
{
  char			    bit = IS_NEG(game->state.d);

  game->state.d = (game->state.d << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.d);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_e(t_game *game)
{
  char			    bit = IS_NEG(game->state.e);

  game->state.e = (game->state.e << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.e);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_h(t_game *game)
{
  char			    bit = IS_NEG(game->state.h);

  game->state.h = (game->state.h << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.h);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_l(t_game *game)
{
  char			    bit = IS_NEG(game->state.l);

  game->state.l = (game->state.l << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.l);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rl_hl(t_game *game)
{
  char			    bit = IS_NEG(game->state.a);

  game->state.a = (game->state.a << 1) | get_C(&game->state.f);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}



int                 i_rrc_a(t_game *game)
{
  char			    bit = (game->state.a & 1);

  game->state.a = (game->state.a >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_b(t_game *game)
{
  char			    bit = (game->state.b & 1);

  game->state.b = (game->state.b >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.b);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_c(t_game *game)
{
  char			    bit = (game->state.c & 1);

  game->state.c = (game->state.c >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.c);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_d(t_game *game)
{
  char			    bit = (game->state.d & 1);

  game->state.d = (game->state.d >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.d);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_e(t_game *game)
{
  char			    bit = (game->state.e & 1);

  game->state.e = (game->state.e >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.e);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_h(t_game *game)
{
  char			    bit = (game->state.h & 1);

  game->state.h = (game->state.h >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.h);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_l(t_game *game)
{
  char			    bit = (game->state.l & 1);

  game->state.l = (game->state.l >> 1) | (bit << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.l);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rrc_hl(t_game *game)
{
  uint8_t           value = read_byte(&game->state, game->state.hl);
  char			    bit = (value & 1);
  uint8_t           result = (value >> 1) | (bit << 7);

  write_byte(&game->state, game->state.hl, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, result);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}



int                 i_rr_a(t_game *game)
{
  char			    bit = (game->state.a & 1);

  game->state.a = (game->state.a >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_b(t_game *game)
{
  char			    bit = (game->state.b & 1);

  game->state.b = (game->state.b >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.b);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_c(t_game *game)
{
  char			    bit = (game->state.c & 1);

  game->state.c = (game->state.c >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.c);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_d(t_game *game)
{
  char			    bit = (game->state.d & 1);

  game->state.d = (game->state.d >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.d);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_e(t_game *game)
{
  char			    bit = (game->state.e & 1);

  game->state.e = (game->state.e >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.e);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_h(t_game *game)
{
  char			    bit = (game->state.h & 1);

  game->state.h = (game->state.h >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.h);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_l(t_game *game)
{
  char			    bit = (game->state.l & 1);

  game->state.l = (game->state.l >> 1) | (get_C(&game->state.f) << 7);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, game->state.l);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_rr_hl(t_game *game)
{
  uint8_t           value = read_byte(&game->state, game->state.hl);
  char			    bit = (value & 1);
  uint8_t           result = (value >> 1) | (get_C(&game->state.f) << 7);

  write_byte(&game->state, game->state.hl, result);
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  zero_flag_check(&game->state.f, result);
  if (bit)
    set_C(&game->state.f);
  else 
    reset_C(&game->state.f);
  return RETURN_SUCCESS;
}
