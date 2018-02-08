#ifndef OPTS_H_
# define OPTS_H_

# include <unistd.h>

typedef struct      s_opts
{
    int             card_fd;
    int             card_size;
    char            *card_path;
    char            *card_content;
}                   t_opts;

int                 parse_command_line(int argc, char **argv, t_opts *options);
void                verb_options(const t_opts *options);

#endif /* !OPTS_H_ */
