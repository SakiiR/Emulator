#include <SDL/SDL.h>
#include <stdio.h>
#include "resource.h"
#include "game.h"
#include "cpu.h"
#include "video.h"

static char         parse_event(SDL_Event *event, t_game *game)
{
  (void)game;
  if (event != NULL)
  {
    if (event->type ==SDL_QUIT)
    {
      fprintf(stderr, "Exiting ..\n");
      return RETURN_FAILURE;
    }
    if (event->type == SDL_KEYDOWN)
    {
      switch(event->key.keysym.sym)
      {
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
  while (1)
  {
    SDL_PollEvent(&event);
    cpu_step(&game->state, &game->options);
    if (parse_event(&event, game) == RETURN_FAILURE)
      return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
