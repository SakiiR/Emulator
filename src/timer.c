#include "resource.h"
#include "game.h"
#include "timer.h"
#include "instructions.h"

int                     init_timer(t_timer *timer)
{
  timer->div = 0;
  timer->timer = 0;
  return RETURN_SUCCESS;
}

static char             timer_enabled(t_game *game)
{
  return *game->state.hregisters.TAC & TIMER_ENABLED;
}

int                     timer_step(t_game *game)
{
  static unsigned int   frequencies[] = {4096, 16384, 65536, 262144};
  uint8_t               *tac = game->state.hregisters.TAC;
  t_timer               *timer = &game->timer;
  uint8_t               *div = game->state.hregisters.DIV;
  unsigned int          frequency = frequencies[*tac & TIMER_OFFSET];


  /* Update the div register */
  timer->div += game->state.instruction->cycle_count;
  if (timer->div > MAX_DIV)
  {
    timer->div -= MAX_DIV;
    if (*div == 0xFF)
      *div = 0;
    else
      *div += 1;
  }

  if (!timer_enabled(game))
    return RETURN_SUCCESS;

  /* Process timer step */
  timer->timer = game->state.instruction->cycle_count;
  
  /* If we have to process timer */
  if (timer->timer > frequency)
  {
    timer->timer -= frequency;
    /* Check for tima overflow */
    if (*game->state.hregisters.TIMA == 0xFF)
    {
      *game->state.hregisters.TIMA = *game->state.hregisters.TMA;    
      trigger_interrupt(game, TIMER);
    }
    else
      ++timer->timer;
  }
  return RETURN_SUCCESS;
}
