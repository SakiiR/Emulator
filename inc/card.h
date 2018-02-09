#ifndef CARD_H_
# define CARD_H_

# include <stdint.h>
# include "opts.h"

# define HEADER_SIZE  (0x14F)

# define CTITLE_B     (0x134)
# define CTITLE_E     (0x143)
# define CTITLE_SIZE  (0x10)

# define CLISCENSEE_B     (0x144)
# define CLISCENSEE_E     (0x145)
# define CLISCENSEE_SIZE  (0x2)

# define ROMSIZE_B        (0x148)
# define RAMSIZE_B        (0x149)

# define JAPANESE_B       (0x14a)

# define VERSION_B        (0x14c)

# define CHECKSUM_B       (0x14d)
# define CTYPE_B          (0x147)

# include "card_type.h"

typedef struct      s_cardtype
{
  uint8_t           id;
  char              *value;
}                   t_cardtype;

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
  t_cardtype        card_type;
  size_t            rom_size;
  size_t            ram_size;
  uint16_t          japanese;
  unsigned char     version;
  unsigned char     h_checksum; 
}                   t_card;



int                 dump_card(t_opts *options, t_card *card);
int                 read_card(t_card *card);
void                verb_card(t_card *card);

#endif /* !CARD_H_ */
