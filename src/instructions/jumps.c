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
  (void)state;
  return RETURN_SUCCESS;
}

int                 i_jp_z_nn(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

int                 i_jp_nc_nn(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

int                 i_jp_c_nn(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}
