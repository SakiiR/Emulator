#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"


t_instruction       g_instructions[] = {
  #include "instructions.inc"
};


int          unimplemented_instruction(t_8080state *state)
{
    fprintf(stderr, "[-] UnImplemented Instruction at 0x%x\n", state->pc);
    return RETURN_FAILURE;
}
