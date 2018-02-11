#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int             i_call_nn(t_cpustate *state)
{
  uint16_t      to = state->op16;   

  push_word(state, state->pc + 3);
  state->pc = to;
  return RETURN_SUCCESS;
}
