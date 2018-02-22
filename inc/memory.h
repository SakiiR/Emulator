#ifndef MEMORY_H_
# define MEMORY_H_

# include <stdint.h>
# include "card.h"
# include "cpu.h"

typedef struct          s_memory
{
  uint8_t               *start; /* 0xFFFF memory base */
}                       t_memory;


int                     init_memory(struct s_memory *memory, t_card *card);

#endif /* !MEMORY_H_ */
