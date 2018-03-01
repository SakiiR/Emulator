#include "resource.h"
#include "game.h"
#include "interrupts.h"

void                        init_interrupts(t_interrupts *interrupts)
{
  interrupts->enabled = INTERRUPTS_ENABLED;
}

char                        interrupts_step(t_game *game)
{
  uint8_t                   interrupts_registers = (*game->state.hregisters.IF & 
                                                    *game->state.hregisters.IE);
  static const uint8_t      interrupts[] = {

    VBLANK_HANDLER,
    LCDSTAT_HANDLER,
    TIMER_HANDLER,
    SERIAL_HANDLER,
    JOYPAD_HANDLER
  };
  if (!(interrupts_registers && game->interrupts.enabled == INTERRUPTS_ENABLED))
    return RETURN_FAILURE;
  for (unsigned i = 0; i < (sizeof(interrupts) / sizeof(interrupts[0])); ++i)
    printf("i: %d\n", i);
  return RETURN_SUCCESS;
}
