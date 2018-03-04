#ifndef VIDEO_H_
# define VIDEO_H_

# include <SDL/SDL.h>

# define SDL_WINDOW_X                     (640)
# define SDL_WINDOW_Y                     (480)

# define SCREEN_WIDTH                     (160)
# define SCREEN_HEIGHT                    (144)

# define HBLANK_CYCLES                    (204)
# define VBLANK_CYCLES                    (456)
# define OEM_SEARCH_CYCLES                (80)
# define PIXEL_TRANSFER_CYCLES            (172)

# define DEFAULT_COLOR                    (0xff)

# define SET_STAT_SCREEN_MODE(stat, mode) (((stat) & (0xFF ^ 0x3)) | (mode))

enum                                      e_stat_screen_mode
{
  MODE_HBLANK = 0,
  MODE_VBLANK = 1,
  MODE_OEM_SEARCH = 2,
  MODE_PIXEL_TRANSFER = 3
};

typedef struct s_game                   t_game;

typedef struct                            s_gpu
{
  SDL_Surface                             *screen;
  unsigned long long                      cycles;
}                                         t_gpu;

typedef struct                            s_mode_handler
{
  void                                    (*handler)(struct s_game *game);
  unsigned long                           cycle_count;
}                                         t_mode_handler;

SDL_Surface                               *setup_SDL();
void                                      refresh(t_game *game);
void                                      destroy_SDL(SDL_Surface *screen);
int                                       gpu_step(t_game *game);
void                                      init_gpu(t_gpu *gpu);

#endif /* !VIDEO_H_ */
