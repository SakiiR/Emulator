#include <SDL/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include "resource.h"
#include "game.h"
#include "cpu.h"
#include "video/video.h"
#include "utils.h"
#include "interrupts.h"
#include "timer.h"
#include "timing.h"

static char         parse_event(SDL_Event *event, t_game *game)
{
  if (event != NULL)
  {
    if (event->type ==SDL_QUIT)
    {
      fprintf(stderr, "[-] Exiting ..\n");
      return RETURN_FAILURE;
    }
    if (event->type == SDL_KEYDOWN)
    {
      switch(event->key.keysym.sym)
      {
        case SDLK_m:
          dump_memory(game);
          break;
        case SDLK_v:
          dump_vram(game);
          break;
        case SDLK_p:
          verb_state(&game->state);
          break;
        default:
          break;
      }
    }
  }
  return RETURN_SUCCESS;
}

int                 game_loop(t_game *game)
{
  SDL_Event         event;

  if (init_cpu(&game->state, &game->card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  init_interrupts(&game->interrupts);
  init_timer(&game->timer);
  init_gpu(&game->gpu);
  while (1)
  {
    SDL_PollEvent(&event);
    if (cpu_step(game, game->options.verbose) == RETURN_FAILURE)
      return RETURN_FAILURE;
    gpu_step(game);
    timer_step(game);
    interrupts_step(game);
    timing_step(game);
    if (parse_event(&event, game) == RETURN_FAILURE)
      return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
