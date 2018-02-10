#include "resource.h"
#include "cpu.h"
#include "memory.h"


/**
 * Jump to next word
 */
int                 i_jp_nn(t_cpustate *state)
{
  state->pc = read_16(&state->memory.start[state->pc + 1]);
  return RETURN_SUCCESS;
}
