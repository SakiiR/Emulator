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
  if (get_Z(&state->f) == BIT_RESET)
    state->pc = state->op16;
  return RETURN_SUCCESS;
}

int                 i_jp_z_nn(t_cpustate *state)
{
  if (get_Z(&state->f) == BIT_SET)
    state->pc = state->op16;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jp_nc_nn(t_cpustate *state)
{
  if (get_C(&state->f) == BIT_RESET)
    state->pc = state->op16;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jp_c_nn(t_cpustate *state)
{
  if (get_C(&state->f) == BIT_SET)
    state->pc = state->op16;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jp_hl(t_cpustate *state)
{
  state->pc = state->hl;
  return RETURN_SUCCESS;
}

int                 i_jp_n(t_cpustate *state)
{
  state->pc += state->op8;
  return RETURN_SUCCESS;
}

int                 i_jr_nz_sharp(t_cpustate *state)
{
  if (!get_Z(&state->f))
    state->pc += state->op8;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jr_z_sharp(t_cpustate *state)
{
  if (get_Z(&state->f) == BIT_SET)
    state->pc += state->op8;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jr_nc_sharp(t_cpustate *state)
{
  if (get_C(&state->f) == BIT_RESET)
    state->pc += state->op8;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}

int                 i_jr_c_sharp(t_cpustate *state)
{
  if (get_C(&state->f) == BIT_SET)
    state->pc += state->op8;
  else 
    ++state->pc;
  return RETURN_SUCCESS;
}
