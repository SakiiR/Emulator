#include <stdlib.h>
#include <stdio.h>
#include "resource.h"
#include "opts.h"
#include "card.h"

int             main(int argc, char **argv)
{
    t_opts      options;

    if (parse_command_line(argc, argv, &options) == RETURN_FAILURE)
        return RETURN_FAILURE;
    dump_card(&options);
    verb_options(&options);
    free(options.card_content);
    return RETURN_SUCCESS;
}
