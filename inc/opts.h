#ifndef OPTS_H_
# define OPTS_H_

# include <unistd.h>
# include "video.h"

typedef struct      s_opts
{
    int             card_fd;
    char            *card_path;
    char            step_by_step;
    char            verbose;
    SDL_Surface     *screen;
}                   t_opts;

int                 parse_command_line(int argc, char **argv, t_opts *options);
void                verb_options(const t_opts *options);

#endif /* !OPTS_H_ */
