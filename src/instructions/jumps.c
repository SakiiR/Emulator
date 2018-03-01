#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"


/**
 * Jump to next word
 */
int                 i_jp_nn(t_game *game)
{
  game->state.pc = game->state.op16;
  return RETURN_SUCCESS;
}


int                 i_jp_nz_nn(t_game *game)
{
  if (!get_Z(&game->state.f))
    game->state.pc = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_jp_z_nn(t_game *game)
{
  if (get_Z(&game->state.f))
    game->state.pc = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_jp_nc_nn(t_game *game)
{
  if (!get_C(&game->state.f))
    game->state.pc = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_jp_c_nn(t_game *game)
{
  if (get_C(&game->state.f))
    game->state.pc = game->state.op16;
  return RETURN_SUCCESS;
}

int                 i_jp_hl(t_game *game)
{
  game->state.pc = game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_jp_n(t_game *game)
{
  game->state.pc += game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_jr_nz_sharp(t_game *game)
{
  if (!get_Z(&game->state.f))
    game->state.pc += game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_jr_z_sharp(t_game *game)
{
  if (get_Z(&game->state.f))
    game->state.pc += game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_jr_nc_sharp(t_game *game)
{
  if (!get_C(&game->state.f))
    game->state.pc += game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_jr_c_sharp(t_game *game)
{
  if (get_C(&game->state.f))
    game->state.pc += game->state.op8;
  return RETURN_SUCCESS;
}
