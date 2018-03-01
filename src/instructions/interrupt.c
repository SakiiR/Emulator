#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "interrupts.h"
#include "memory.h"
#include "memory_ar.h"

int             i_di(t_game *game)
{
  game->interrupts.enabled = INTERRUPTS_DISABLED;
  return RETURN_SUCCESS;
}

int             i_ei(t_game *game)
{
  game->interrupts.enabled = INTERRUPTS_ENABLED;
  return RETURN_SUCCESS;
}
