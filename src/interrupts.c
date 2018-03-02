#include "resource.h"
#include "game.h"
#include "memory_ar.h"
#include "interrupts.h"

void                        init_interrupts(t_interrupts *interrupts)
{
  interrupts->enabled = INTERRUPTS_ENABLED;
}

int                         trigger_interrupt(t_game *game, const enum e_interrupt_type type)
{
  *game->state.hregisters.IF |= type;
  return RETURN_SUCCESS;
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
  for (unsigned int i = 0; i < (sizeof(interrupts)); ++i)
  {
    if (interrupts_registers & (1 << i))
    {
      printf("[~] Interruption triggered!\n");
      /* Restoring interrupt flag and enable */
      *game->state.hregisters.IF &= (0xFF ^ (1 << i));
      game->interrupts.enabled = INTERRUPTS_DISABLED;
      /* Save PC and jump to interrupt handler */
      push_word(&game->state, game->state.pc);
      game->state.pc = interrupts[i];
    }
  }
  return RETURN_SUCCESS;
}
