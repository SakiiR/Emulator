#ifndef MEMORY_H_
# define MEMORY_H_

# define M_LITTLE_ENDIAN

# include <stdint.h>
# include "card.h"
# include "cpu.h"

typedef struct          s_memory
{
  uint8_t               *start; /* 0xFFFF memory base */
}                       t_memory;

uint8_t                 read_8(uint8_t *memory);
uint16_t                read_16(uint8_t *memory);
uint32_t                read_32(uint8_t *memory);

int                     init_memory(struct s_memory *memory, t_card *card);

#endif /* !MEMORY_H_ */
