#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "card.h"
#include "opts.h"
#include "resource.h"

const t_liscensee   g_liscensees[] = {
  #include "liscensees.inc"
};

static int          init_card(t_card * card)
{
  card->content = NULL;
  card->size = 0;
  return RETURN_SUCCESS;
}


/**
 * Read the card content to the t_card content 
 * attribute (heap).
 */
int                 dump_card(t_opts *options, t_card *card)
{
  struct stat       s;
  char              *p;
  int               byte_read = 0;

  if (init_card(card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  if (fstat(options->card_fd, &s) == SYSCALL_ERROR)
  {
    perror("fstat");
    return RETURN_FAILURE;
  }
  card->size = s.st_size;
  if (card->size <= HEADER_SIZE)
  {
    fprintf(stderr, NO_GBCARD);
    return RETURN_FAILURE;
  }
  if ((card->content = malloc((sizeof(*card->content) * card->size) + 1)) == NULL)
  {
    fprintf(stderr, MALLOC_FAILURE);
    return RETURN_FAILURE;
  }
  p = card->content;
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

int                 read_card(t_card *card)
{
  int               i;

  /* Read Title */
  strncpy(card->title, &card->content[CTITLE_B], CTITLE_SIZE);
  card->title[CTITLE_SIZE] = 0;
  /* Read Liscensee */
  strncpy(card->liscensee.code, &card->content[CLISCENSEE_B], CLISCENSEE_SIZE);
  card->liscensee.code[CLISCENSEE_SIZE] = 0;
  for (i = 0; i < (int)sizeof(g_liscensees) ; ++i)
  {
    if (strcmp(g_liscensees[i].code, card->liscensee.code) == 0)
    {
      card->liscensee.display_name = g_liscensees[i].display_name;
      break;
    }
  }
  return RETURN_SUCCESS;
}


void                verb_card(t_card *card)
{
  printf("####### Card Information ########\n");
  printf("\tcontent      : %.10s [...]\n", card->content);
  printf("\tsize         : %d\n", (int)card->size);
  printf("\ttitle        : %s\n", card->title);
  printf("\tliscensee    : %s:%s\n", card->liscensee.code, card->liscensee.display_name);
}
