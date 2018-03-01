#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

int             i_call_nn(t_game *game)
{
  uint16_t      to = game->state.op16;   

  push_word(&game->state, game->state.pc);
  game->state.pc = to;
  return RETURN_SUCCESS;
}

int             i_call_nz_nn(t_game *game)
{
  if (!get_Z(&game->state.f))
  {
    push_word(&game->state, game->state.pc);
    game->state.pc = game->state.op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_z_nn(t_game *game)
{
  if (get_Z(&game->state.f))
  {
    push_word(&game->state, game->state.pc);
    game->state.pc = game->state.op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_nc_nn(t_game *game)
{
  if (!get_C(&game->state.f))
  {
    push_word(&game->state, game->state.pc);
    game->state.pc = game->state.op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_c_nn(t_game *game)
{
  if (get_C(&game->state.f))
  {
    push_word(&game->state, game->state.pc);
    game->state.pc = game->state.op16;
  }
  return RETURN_SUCCESS;
}
