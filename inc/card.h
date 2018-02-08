#ifndef CARD_H_
# define CARD_H_

# include "opts.h"

# define HEADER_SIZE  (0x14F)

# define CTITLE_B     (0x134)
# define CTITLE_E     (0x143)
# define CTITLE_SIZE  (0x10)

# define CLISCENSEE_B     (0x144)
# define CLISCENSEE_E     (0x145)
# define CLISCENSEE_SIZE  (0x2)

typedef struct      s_liscensee
{
  char              code[CLISCENSEE_SIZE + 1];
  char              *display_name;

}                   t_liscensee;

typedef struct      s_card
{
  char              title[CTITLE_SIZE + 1];
  char              *content;
  size_t            size;
  t_liscensee       liscensee;
}                   t_card;



int                 dump_card(t_opts *options, t_card *card);
int                 read_card(t_card *card);
void                verb_card(t_card *card);

#endif /* !CARD_H_ */
