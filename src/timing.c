#include <time.h>
#include <stdio.h>
#include "resource.h"
#include "timer.h"
#include "timing.h"
#include "instructions.h"
#include "game.h"


int                 timing_step(t_game *game)
{
  struct timespec   res = {0, 0};

  clock_gettime(CLOCK_MONOTONIC_RAW, &res);
  printf("Time: %lu\n", res.tv_nsec);
  game->timer.cycles += game->state.instruction->cycle_count;
  if (game->timer.cycles > MAX_CYCLE_TO_REFRESH)
  {
    
  }
  return RETURN_SUCCESS;
}
