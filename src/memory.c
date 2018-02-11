#include <string.h>
#include "resource.h"
#include "cpu.h"
#include "memory.h"

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
