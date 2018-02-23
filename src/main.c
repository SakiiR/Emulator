#include <stdlib.h>
#include <stdio.h>
#include "resource.h"
#include "game.h"
#include "opts.h"
#include "card.h"
#include "cpu.h"
#include "video.h"


int             main(int argc, char **argv)
{
  t_game        game;  

  if (parse_command_line(argc, argv, &game.options) == RETURN_FAILURE)
    return RETURN_FAILURE;
  if (dump_card(&game.options, &game.card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  if (read_card(&game.card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  verb_card(&game.card);
  if (game.card.card_type.id != CTYPE_ROMONLY)
  {
    fprintf(stderr, "[-] Sorry, only ROM_Only CB can be run on this emulator .. \n");
    return RETURN_FAILURE;
  }
  if ((game.gpu.screen = setup_SDL()) == NULL)
    return RETURN_FAILURE;
  if (game_loop(&game) == RETURN_FAILURE)
    return RETURN_FAILURE;
  destroy_SDL(game.options.screen);
  return RETURN_SUCCESS;
}
