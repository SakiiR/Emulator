#include "resource.h"
#include "cpu.h"
#include "memory.h"


/**
 * Jump to next word
 */
int                 i_jp_nn(t_cpustate *state)
{
  state->pc = state->op16;
  return RETURN_SUCCESS;
}


int                 i_jp_nz_nn(t_cpustate *state)
{
  if (state->flags.z == REGISTER_RESET)
    state->pc = state->op16;
  return RETURN_SUCCESS;
}

int                 i_jp_z_nn(t_cpustate *state)
{
  if (state->flags.z == REGISTER_SET)
    state->pc = state->op16;
  return RETURN_SUCCESS;
}

int                 i_jp_nc_nn(t_cpustate *state)
{
  if (state->flags.c == REGISTER_RESET)
    state->pc = state->op16;
  return RETURN_SUCCESS;
}

int                 i_jp_c_nn(t_cpustate *state)
{
  if (state->flags.c == REGISTER_SET)
    state->pc = state->op16;
  return RETURN_SUCCESS;
}
