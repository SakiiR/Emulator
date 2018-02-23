#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int             i_call_nn(t_cpustate *state)
{
  uint16_t      to = state->op16;   

  push_word(state, state->pc);
  state->pc = to;
  return RETURN_SUCCESS;
}

int             i_call_nz_nn(t_cpustate *state)
{
  if (!get_Z(&state->f))
  {
    push_word(state, state->pc);
    state->pc = state->op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_z_nn(t_cpustate *state)
{
  if (get_Z(&state->f))
  {
    push_word(state, state->pc);
    state->pc = state->op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_nc_nn(t_cpustate *state)
{
  if (!get_C(&state->f))
  {
    push_word(state, state->pc);
    state->pc = state->op16;
  }
  return RETURN_SUCCESS;
}

int             i_call_c_nn(t_cpustate *state)
{
  if (get_C(&state->f))
  {
    push_word(state, state->pc);
    state->pc = state->op16;
  }
  return RETURN_SUCCESS;
}
