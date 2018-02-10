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

const t_cardtype    g_cardtypes[] = {
  #include "cardtypes.inc"
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
  card->liscensee.display_name = NULL;
  for (i = 0; g_liscensees[i].display_name != NULL ; ++i)
  {
    if (strcmp(g_liscensees[i].code, card->liscensee.code) == 0)
    {
      card->liscensee.display_name = g_liscensees[i].display_name;
      break;
    }
  }
  /* Read Card Type*/
  card->card_type.value = NULL;
  card->card_type.id = card->content[CTYPE_B];
  for (i = 0 ; g_cardtypes[i].value != NULL ; ++i)
  {
    if (g_cardtypes[i].id == card->card_type.id)
    {
      card->card_type.value = g_cardtypes[i].value;
      break;
    }
  }
  /* Read ROM size */
  card->rom_size = 32000 << card->content[ROMSIZE_B];
  /* Read RAM size (find better way) */
  switch (card->content[RAMSIZE_B])
  {
    case 0x00:
      card->ram_size = 0;
      break;
    case 0x01:
      card->ram_size = 2000;
      break;
    case 0x02:
      card->ram_size = 8000;
      break;
    case 0x03:
      card->ram_size = 32000;
      break;
    case 0x04:
      card->ram_size = 128000;
      break;
    case 0x05:
      card->ram_size = 64000;
      break;
  }
  /* Read japanese mode */
  card->japanese = card->content[JAPANESE_B];
  /* Read version */
  card->version = card->content[VERSION_B];
  /* Read checksum */
  card->h_checksum = card->content[CHECKSUM_B];
  return RETURN_SUCCESS;
}

static void             display_nbyte(const char *buffer, size_t n)
{
  size_t                i;

  for (i = 0 ; i < n ; ++i)
    printf(" %02x", buffer[i] & 0xff);
}

static unsigned char    compute_checksum(t_card *card)
{
  int                   i;
  unsigned char         x = 0;

  for (i = 0x134 ; i < 0x14C+1 ; ++i)
    x = (x - card->content[i] - 1) & 0xff;
  return x;
}

void                    verb_card(t_card *card)
{
  int                   checksum = compute_checksum(card);

  printf("####### Card Information ########\n");
  printf("\tcontent      :");
  display_nbyte(card->content, 0x10);
  printf(" [...]\n");
  printf("\tsize         : %d\n", (int)card->size);
  printf("\ttitle        : %s\n", card->title);
  printf("\tliscensee    : %s   -> %s\n", card->liscensee.code, card->liscensee.display_name);
  printf("\ttype         : 0x%02x -> %s\n", card->card_type.id, card->card_type.value);
  printf("\tROM size     : 0x%x bytes or %d bytes\n", (int)card->rom_size, (int)card->rom_size);
  printf("\tRAM size     : 0x%x bytes or %d bytes (%s)\n", (int)card->ram_size, (int)card->ram_size, card->ram_size==0?"No RAM":"");
  printf("\tDestination  : %sJapanese\n", card->japanese==0x00?"":"Non-");
  printf("\tVersion      : 0x%02x\n", card->version);
  printf("\tChecksum     : 0x%02x, match 0x%02x ? %s\n", card->h_checksum, checksum, (checksum == card->h_checksum ? "Yes" : "No"));
}
