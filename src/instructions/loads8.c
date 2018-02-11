#include "resource.h"
#include "cpu.h"


int                 i_ld8_b_n(t_cpustate *state)
{
  state->b = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_n(t_cpustate *state)
{
  state->c = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_n(t_cpustate *state)
{
  state->d = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_n(t_cpustate *state)
{
  state->e = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_n(t_cpustate *state)
{
  state->h = state->op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_n(t_cpustate *state)
{
  state->l = state->op8;
  return RETURN_SUCCESS;
}
