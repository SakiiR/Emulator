#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int                 i_ret(t_cpustate *state)
{
  state->pc = pop_word(state);
  return RETURN_SUCCESS;
}

int                 i_ret_nz(t_cpustate *state)
{
  if (!get_Z(&state->f))
    state->pc = pop_word(state);
  return RETURN_SUCCESS;
}

int                 i_ret_z(t_cpustate *state)
{
  if (get_Z(&state->f))
    state->pc = pop_word(state);
  return RETURN_SUCCESS;
}

int                 i_ret_nc(t_cpustate *state)
{
  if (!get_C(&state->f))
    state->pc = pop_word(state);
  return RETURN_SUCCESS;
}

int                 i_ret_c(t_cpustate *state)
{
  if (get_C(&state->f))
    state->pc = pop_word(state);
  return RETURN_SUCCESS;
}

int                 i_reti(t_cpustate *state)
{
  state->pc = pop_word(state);
  // TODO: Enable interrupts
  return RETURN_SUCCESS;
}




