#include <string.h>
#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "register.h"
#include "memory_ar.h"


int                 unimplemented_instruction(t_cpustate *state)
{
  t_instruction     instruction = g_instructions[state->memory.start[state->old_pc]];

  fprintf(stderr, 
          "[-] Unimplemented Instruction at 0x%04x (%s) (0x%02x)\n",
          state->old_pc,
          instruction.operation,
          state->memory.start[state->old_pc]
         );
  return RETURN_FAILURE;
}

int                 i_prefix(t_cpustate *state)
{
  t_instruction     i = g_instructions_cb[state->memory.start[state->pc + 1]];
  printf("[+] Triggering CB instruction (%s)\n", i.operation);
  return g_instructions_cb[(int)state->op8].handler(state);
}

