#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"
#include "interrupts.h"

int                 i_ret(t_game *game)
{
  game->state.pc = pop_word(game);
  return RETURN_SUCCESS;
}

int                 i_reti(t_game *game)
{
  game->state.pc = pop_word(game);
  game->interrupts.enabled = INTERRUPTS_ENABLED;
  return RETURN_SUCCESS;
}

int                 i_ret_nz(t_game *game)
{
  if (!get_Z(&game->state.f))
    game->state.pc = pop_word(game);
  return RETURN_SUCCESS;
}

int                 i_ret_z(t_game *game)
{
  if (get_Z(&game->state.f))
    game->state.pc = pop_word(game);
  return RETURN_SUCCESS;
}

int                 i_ret_nc(t_game *game)
{
  if (!get_C(&game->state.f))
    game->state.pc = pop_word(game);
  return RETURN_SUCCESS;
}

int                 i_ret_c(t_game *game)
{
  if (get_C(&game->state.f))
    game->state.pc = pop_word(game);
  return RETURN_SUCCESS;
}

