#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"

int                 search_instruction(uint8_t opcode, t_cpustate *state)
{
  unsigned int      i = 0;
  int               ret = RETURN_SUCCESS;

  for (i = 0 ; i <= 0xff ; ++i)
  {
    if (opcode == g_instructions[i].opcode)
    {
      ret = g_instructions[i].handler(state);
      state->pc += g_instructions[i].size;
      return ret;
    }
  }
  fprintf(stderr, "[-] Failed to find instruction 0x%x\n", opcode);
  return RETURN_FAILURE;
}


int                 unimplemented_instruction(t_cpustate *state)
{
    fprintf(stderr, "[-] Unimplemented Instruction at 0x%04x (0x%02x)\n", state->pc, state->memory.start[state->pc]);
    return RETURN_FAILURE;
}

int                 i_nop(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}
