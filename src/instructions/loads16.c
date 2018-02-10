#include "resource.h"
#include "cpu.h"
#include "memory.h"


/**
 * Put 16 bits nn into bc 
 */
int                 instruction_ld16_bc_nn(t_cpustate *state)
{
  uint16_t          value = read_16(&state->memory[state->pc + 1]);
  
  write_bc(state, value);
  ++state->pc;
  return RETURN_SUCCESS;
}

/**
 * Put 16 bits nn into hl 
 */
int                 instruction_ld16_hl_nn(t_cpustate *state)
{
  uint16_t          value = read_16(&state->memory[state->pc + 1]);
  
  write_hl(state, value);
  ++state->pc;
  return RETURN_SUCCESS;
}
