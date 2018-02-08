#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "opts.h"
#include "resource.h"

static void        init_options(t_opts *options)
{
  options->card_path = NULL;
  options->card_fd = 0;
}

static void         help(const char *prog)
{
  fprintf(stderr, "\n##### - Welcome - #####\n");
  fprintf(stderr, "USAGE: %s -c <card>\n", prog);
}

static int          check_options(t_opts *options)
{
  if (options->card_path == NULL)
  {
    fprintf(stderr, "[-] Missing card path\n");
    return RETURN_FAILURE;
  }
  if ((options->card_fd = open(options->card_path, O_RDONLY)) == SYSCALL_ERROR)
  {
    fprintf(stderr, "[-] Failed to open '%s' in read mode\n", options->card_path);
    return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}

void                verb_options(const t_opts *options)
{
  printf("#############\n");
  printf("Options: %p\n", options);
  printf("\tCard Path    : %s\n", options->card_path);
  printf("\tCard Fd      : %d\n", options->card_fd);
  printf("#############\n");
}

int                 parse_command_line(int argc, char **argv, t_opts *options)
{
  int             c;

  init_options(options);
  while ((c = getopt(argc, argv, "hc:")) != SYSCALL_ERROR)
  {

    switch(c)
    {
      case 'c':
        options->card_path = optarg;
        break;
      case 'h':
        help(argv[0]);
        return RETURN_FAILURE;
      case '?':
        help(argv[0]);
        return RETURN_FAILURE;
      default:
        break;
    }
  }
  if (check_options(options) == RETURN_FAILURE)
  {
    help(argv[0]);
    return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
