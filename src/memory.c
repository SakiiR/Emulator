#include <string.h>
#include "resource.h"
#include "cpu.h"
#include "memory.h"

uint8_t                 read_8(uint8_t *memory)
{
  return memory[0];
}

uint16_t                read_16(uint8_t *memory)
{
  return memory[1] << 8 | memory[0];
}

uint32_t                read_32(uint8_t *memory)
{
  return memory[0] | (memory[1] << 8) | (memory[2] << 16) | (memory[3] << 24);
}

/**
 * Init memory pointers and mapping
 */
int                     init_memory(t_memory *memory, t_card *card)
{
  /* Init the whole memory */
  if ((memory->start = malloc((sizeof(*memory) * MEMORY_SIZE))) == NULL)
  {
    fprintf(stderr, MALLOC_FAILURE);
    return RETURN_FAILURE;
  }
  memset(memory->start, 0, MEMORY_SIZE);

  /* Map the cartridge into the memory */
  memcpy(memory->start, card->content, 0x8000);

  /* Init pointers */
  (void)card;
  (void)memory;
  return RETURN_SUCCESS;
}
