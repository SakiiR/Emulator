#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "opts.h"
#include "resource.h"

/**
 * Read the card content to the t_opts card_content attribute (heap).
 */
int                 dump_card(t_opts *options)
{
  struct stat       s;
  char              *p;
  int               byte_read = 0;

  if (fstat(options->card_fd, &s) == SYSCALL_ERROR)
  {
    perror("fstat");
    return RETURN_FAILURE;
  }
  options->card_size = s.st_size;
  options->card_content = malloc((sizeof(*options->card_content) * options->card_size) + 1);
  p = options->card_content;
  while((byte_read = read(options->card_fd, p, READ_SIZE)) > 0)
    p += byte_read;
  if (byte_read == SYSCALL_ERROR)
  {
    perror("read");
    close(options->card_fd);
    return RETURN_FAILURE;
  }
  close(options->card_fd);
  return RETURN_SUCCESS;
}


