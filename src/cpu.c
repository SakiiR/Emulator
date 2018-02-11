#include <stdio.h>
#include <unistd.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "card.h"

/**
 * Launch the loop()
 */
int             emulate(t_card *card)
{
  t_cpustate    state;
  uint8_t       opcode;

  state.pc = ENTRY_POINT;
  state.sp = DEFAULT_SP;
  if (init_memory(&state.memory, card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  while (1)
  {
    opcode = state.memory.start[state.pc];
    if (search_instruction(opcode, &state) == RETURN_FAILURE)
      return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
