#ifndef VIDEO_H_
# define VIDEO_H_

# include <SDL/SDL.h>

# define SDL_WINDOW_X       (640)
# define SDL_WINDOW_Y       (480)

typedef struct s_game       t_game;

typedef struct              s_gpu
{
  SDL_Surface               *screen;
}                           t_gpu;


void                        refresh(t_game *game);
SDL_Surface                 *setup_SDL();
void                        destroy_SDL(SDL_Surface *screen);
int                         gpu_step(t_game *game);

#endif /* !VIDEO_H_ */
