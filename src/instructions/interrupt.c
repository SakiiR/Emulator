#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

int             i_di(t_cpustate *state)
{
  (void)state;
  /* TODO: Disable interrupt */
  return RETURN_SUCCESS;
}
