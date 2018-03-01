#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

int             i_di(t_game *game)
{
  (void)game;
  /* TODO: Disable interrupt */
  return RETURN_SUCCESS;
}

int             i_ei(t_game *game)
{
  (void)game;
  /* TODO: Enable interrupts */
  return RETURN_SUCCESS;
}
