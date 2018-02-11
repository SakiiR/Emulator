#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_ld16_bc_nn(t_cpustate *state)
{
  fill_bc(state, state->op16);
  return RETURN_SUCCESS;
}

int                 i_ld16_de_nn(t_cpustate *state)
{
  fill_de(state, state->op16);
  return RETURN_SUCCESS;
}

int                 i_ld16_sp_nn(t_cpustate *state)
{
  state->sp = state->op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_hl_nn(t_cpustate *state)
{
  fill_hl(state, state->op16);
  return RETURN_SUCCESS;
}
