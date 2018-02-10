#include "resource.h"
#include "cpu.h"
#include "memory.h"


/**
 * Xor A with A 
 */
int                 instruction_xor_a(t_cpustate *state)
{
  state->a ^= state->a;
  ++state->pc;
  return RETURN_SUCCESS;
}
