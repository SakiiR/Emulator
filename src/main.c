#include <stdlib.h>
#include <stdio.h>
#include "resource.h"
#include "opts.h"
#include "card.h"
#include "cpu.h"
#include "video.h"


int             main(int argc, char **argv)
{
  t_opts      options;
  t_card      card;

  if (parse_command_line(argc, argv, &options) == RETURN_FAILURE)
    return RETURN_FAILURE;
  if (dump_card(&options, &card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  if (read_card(&card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  verb_card(&card);
  if (card.card_type.id != CTYPE_ROMONLY)
  {
    fprintf(stderr, "[-] Sorry, only ROM_Only CB can be run on this emulator .. \n");
    return RETURN_FAILURE;
  }
  if ((options.screen = setup_SDL()) == NULL)
    return RETURN_FAILURE;
  if (emulate(&card, &options) == RETURN_FAILURE)
    return RETURN_FAILURE;
  destroy_SDL(options.screen);
  return RETURN_SUCCESS;
}
