#include "resource.h"
#include "game.h"
#include "cpu.h"
#include "video/video.h"
#include "utils.h"

SDL_Surface                     *setup_SDL()
{
  SDL_Surface                   *screen = NULL;

  SDL_Init(SDL_INIT_EVERYTHING);
  if ((screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE)) == NULL)
  {
    fprintf(stderr, "[-] Failed to setup SDL\n");
    return NULL;
  }
  /* Filling the screen with DEFAULT_COLOR */
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR));
  return screen;
}

void                            init_gpu(t_gpu *gpu)
{
  gpu->cycles = 0;
}

void                            refresh(t_game *game)
{
  SDL_Flip(game->gpu.screen);
}

void                            destroy_SDL(SDL_Surface *screen)
{
  SDL_FreeSurface(screen);
  SDL_Quit();
}

static void                     mode_h_hblank(t_game *game)
{
  ++*game->state.hregisters.LY;
  if (*game->state.hregisters.LY == SCREEN_HEIGHT - 1)
  {
    *game->state.hregisters.LY = 0;
    *game->state.hregisters.STAT = SET_STAT_SCREEN_MODE(*game->state.hregisters.STAT, MODE_VBLANK);
  }
  else
    *game->state.hregisters.STAT = SET_STAT_SCREEN_MODE(*game->state.hregisters.STAT, MODE_OEM_SEARCH);
}

static void                     mode_h_vblank(t_game *game)
{
  ++*game->state.hregisters.LY;
  if (*game->state.hregisters.LY == 153)
  {
    *game->state.hregisters.LY = 0;
    *game->state.hregisters.STAT = SET_STAT_SCREEN_MODE(*game->state.hregisters.STAT, MODE_OEM_SEARCH);
    trigger_interrupt(game, VBLANK);
  }
}

static void                     mode_h_oem_search(t_game *game)
{
  *game->state.hregisters.STAT = SET_STAT_SCREEN_MODE(*game->state.hregisters.STAT, MODE_PIXEL_TRANSFER);
}

static void                     mode_h_pixel_transfer(t_game *game)
{
  *game->state.hregisters.STAT = SET_STAT_SCREEN_MODE(*game->state.hregisters.STAT, MODE_HBLANK);
}

int                             gpu_step(t_game *game)
{
  uint8_t                       gpu_mode = *game->state.hregisters.STAT & 3;
  const t_mode_handler          *mode_handler = NULL;
  /* Handlers for each gpu modes */
  static const t_mode_handler   mode_handlers[] = {
    {&mode_h_hblank,            HBLANK_CYCLES},
    {&mode_h_vblank,            VBLANK_CYCLES},
    {&mode_h_oem_search,        OEM_SEARCH_CYCLES},
    {&mode_h_pixel_transfer,    PIXEL_TRANSFER_CYCLES},
  };

  game->gpu.cycles += 1;
  mode_handler = &mode_handlers[gpu_mode];
  if (mode_handler->handler && game->gpu.cycles > mode_handler->cycle_count)
  {
    mode_handler->handler(game);
    game->gpu.cycles -= mode_handler->cycle_count;
  }
  return RETURN_SUCCESS;
}
