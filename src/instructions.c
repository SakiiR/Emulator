#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"

static void         get_operands(t_cpustate *state)
{
  state->op8 = read_8(&state->memory.start[state->pc + 1]);
  state->op16 = read_16(&state->memory.start[state->pc + 1]);
}

int                 search_instruction(uint8_t opcode, t_cpustate *state)
{
  int               ret = RETURN_SUCCESS;
  t_instruction     instruction = g_instructions[opcode];

  get_operands(state);
  ret = instruction.handler(state);
  state->pc += instruction.size;
  return ret;
}


int                 unimplemented_instruction(t_cpustate *state)
{
  fprintf(stderr, "[-] Unimplemented Instruction at 0x%04x (%s) (0x%02x)\n",
      state->pc,
      g_instructions[state->memory.start[state->pc]].operation,
      state->memory.start[state->pc]);
  return RETURN_FAILURE;
}

int                 i_nop(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}
