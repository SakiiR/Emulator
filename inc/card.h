#ifndef CARD_H_
# define CARD_H_

# include "opts.h"

# define CTITLE_B (0x134)
# define CTITLE_E (0x143)
# define CTITLE_SIZE (0x10)
# define HEADER_SIZE (0x14F)

typedef struct      s_card
{
  char              title[CTITLE_SIZE + 1];
  char              *content;
  size_t            size;
}                   t_card;

int                 dump_card(t_opts *options, t_card *card);
int                 read_card(t_card *card);
void                verb_card(t_card *card);

#endif /* !CARD_H_ */
