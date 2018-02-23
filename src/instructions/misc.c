#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int                 i_stop(t_cpustate *state)
{
  (void)state;
  printf("[~] STOP: Do Nothing yet\n");
  return RETURN_SUCCESS;
}

int                 i_halt(t_cpustate *state)
{
  (void)state;
  printf("[~] HALT: Do Nothing yet\n");
  return RETURN_SUCCESS;
}

int                 i_ccf(t_cpustate *state)
{
  reset_H(&state->f);
  reset_N(&state->f);
  if (get_C(&state->f))
    reset_C(&state->f);
  else
    set_C(&state->f);
  return RETURN_SUCCESS;
}

int                 i_nop(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

int                 i_daa(t_cpustate *state)
{
  if (get_H(&state->f) || (state->a & 0x0F) > 0x9)
    state->a += 6;
  if (get_C(&state->f) || (state->a & 0xF0) > 0x90)
  {
    set_C(&state->f);
    state->a += 96;
  }
  else
    reset_C(&state->f);
  zero_flag_check(&state->f, state->a);
  reset_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_cpl(t_cpustate *state)
{
  state->a = ~state->a;
  reset_N(&state->f);
  reset_H(&state->f);
  get_C(&state->f) ? reset_C(&state->f) : set_C(&state->f);
  return RETURN_SUCCESS;
}
