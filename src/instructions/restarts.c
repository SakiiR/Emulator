#include "resource.h"
#include "cpu.h"

/**
 * Push present address to the stack and jump to 0x0000 + 0x38
 */
int                 instruction_rst_38(t_cpustate *state)
{
  state->pc = 0x0000 + 0x38;
  return RETURN_SUCCESS;
}
