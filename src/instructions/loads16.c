#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_ld16_bc_nn(t_game *game)
{
  game->state.bc = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_de_nn(t_game *game)
{
  game->state.de = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_sp_nn(t_game *game)
{
  game->state.sp = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_hl_nn(t_game *game)
{
  game->state.hl = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_sp_hl(t_game *game)
{
  game->state.sp = game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_ld16_nn_sp(t_game *game)
{
  write_word(&game->state, game->state.op16, game->state.sp);
  return RETURN_SUCCESS;
}
