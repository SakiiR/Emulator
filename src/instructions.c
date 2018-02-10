#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"


t_instruction       g_instructions[] = {
  #include "instructions.inc"
};

int                 search_instruction(uint8_t opcode, t_cpustate *state)
{
  unsigned int      i = 0;

  for (i = 0 ; i <= 0xff ; ++i)
  {
    if (opcode == g_instructions[i].opcode)
      return g_instructions[i].handler(state);
  }
  fprintf(stderr, "[-] Failed to find instruction 0x%x\n", opcode);
  return RETURN_FAILURE;
}


int                 unimplemented_instruction(t_cpustate *state)
{
    fprintf(stderr, "[-] UnImplemented Instruction at 0x%04x (0x%02x)\n", state->pc, state->memory[state->pc]);
    return RETURN_FAILURE;
}

int                 instruction_nop(t_cpustate *state)
{
  ++state->pc;
  return RETURN_SUCCESS;
}

int                 instruction_ld_b_n(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

int                 instruction_ld_c_n(t_cpustate *state)
{

  (void)state;
  return RETURN_SUCCESS;
}

int                 instruction_ld_d_n(t_cpustate *state)  
{
  (void)state;
  return RETURN_SUCCESS;

}

int                 instruction_ld_e_n(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;

}

int                 instruction_ld_h_n(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

int                 instruction_ld_l_n(t_cpustate *state)
{
  (void)state;
  return RETURN_SUCCESS;
}

