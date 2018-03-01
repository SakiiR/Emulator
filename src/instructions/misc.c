#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

int                 i_stop(t_game *game)
{
  (void)game;
  printf("[~] STOP: Do Nothing yet\n");
  return RETURN_SUCCESS;
}

int                 i_halt(t_game *game)
{
  (void)game;
  printf("[~] HALT: Do Nothing yet\n");
  return RETURN_SUCCESS;
}

int                 i_ccf(t_game *game)
{
  reset_H(&game->state.f);
  reset_N(&game->state.f);
  if (get_C(&game->state.f))
    reset_C(&game->state.f);
  else
    set_C(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_nop(t_game *game)
{
  (void)game;
  return RETURN_SUCCESS;
}

int                 i_daa(t_game *game)
{
  if (get_H(&game->state.f) || (game->state.a & 0x0F) > 0x9)
    game->state.a += 6;
  if (get_C(&game->state.f) || (game->state.a & 0xF0) > 0x90)
  {
    set_C(&game->state.f);
    game->state.a += 96;
  }
  else
    reset_C(&game->state.f);
  zero_flag_check(&game->state.f, game->state.a);
  reset_H(&game->state.f);
  return RETURN_SUCCESS;
}

int                 i_cpl(t_game *game)
{
  game->state.a = ~game->state.a;
  reset_N(&game->state.f);
  reset_H(&game->state.f);
  get_C(&game->state.f) ? reset_C(&game->state.f) : set_C(&game->state.f);
  return RETURN_SUCCESS;
}
