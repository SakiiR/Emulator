#include <stdlib.h>
#include <stdio.h>
#include "resource.h"
#include "opts.h"
#include "card.h"

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
    return RETURN_SUCCESS;
}
