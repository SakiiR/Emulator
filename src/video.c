#include "resource.h"
#include "video.h"  

SDL_Surface             *setup_SDL()
{ 
  SDL_Surface           *screen = NULL;

  SDL_Init( SDL_INIT_EVERYTHING );
  if ((screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE )) == NULL)
  {
    fprintf(stderr, "[-] Failed to setup SDL\n");
    return NULL;
  }
  return screen;
}

void                    destroy_SDL(SDL_Surface *screen)
{
  SDL_FreeSurface(screen);
  SDL_Quit();
}
