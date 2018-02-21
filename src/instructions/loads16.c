#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_ld16_bc_nn(t_cpustate *state)
{
  state->bc = state->op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_de_nn(t_cpustate *state)
{
  state->de = state->op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_sp_nn(t_cpustate *state)
{
  state->sp = state->op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_hl_nn(t_cpustate *state)
{
  state->hl = state->op16;
  return RETURN_SUCCESS;
}

int                 i_ld16_sp_hl(t_cpustate *state)
{
  state->sp = state->hl;
  return RETURN_SUCCESS;
}

int                 i_ld16_nn_sp(t_cpustate *state)
{
  write_word(state, state->op16, state->sp);
  return RETURN_SUCCESS;
}
