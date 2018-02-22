#include <string.h>
#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "register.h"

static void         get_operands(t_cpustate *state)
{
  state->op8 = read_8(&state->memory.start[state->pc + 1]);
  state->op16 = read_16(&state->memory.start[state->pc + 1]);
}

static void         verb_state(t_cpustate *state)
{
  t_instruction     instruction = g_instructions[state->memory.start[state->pc]];

  printf("########################################\n\n\n");
  printf(" Instruction %s - 0x%02x                \n", instruction.operation, state->memory.start[state->pc]);
  printf(" Registers:                             \n");
  printf("   A: 0x%02x  F: 0x%02x  AF: 0x%04x     \n", state->a, state->f, state->af);
  printf("   B: 0x%02x  C: 0x%02x  DC: 0x%04x     \n", state->b, state->c, state->bc);
  printf("   D: 0x%02x  E: 0x%02x  DE: 0x%04x     \n", state->d, state->e, state->de);
  printf("   H: 0x%02x  L: 0x%02x  HL: 0x%04x     \n", state->h, state->l, state->hl);
  printf("  PC: 0x%04x             SP: 0x%04x     \n", state->pc, state->sp);
  printf(" Immediate values:                      \n");
  printf("     OP8: 0x%02x       OP16: 0x%04x     \n", (uint8_t)state->op8, (uint16_t)state->op16);
  printf(" Flags:                                 \n");
  printf("     [%c%c%c%c]                         \n", (get_Z(&state->f) ? 'Z' : '-'), (get_N(&state->f) ? 'N' : '-'), (get_H(&state->f) ? 'H' : '-'), (get_C(&state->f) ? 'C' : '-'));
  printf("\n\n");
}

int                 search_instruction(uint8_t opcode, t_cpustate *state)
{
  int               ret = RETURN_SUCCESS;
  t_instruction     instruction = g_instructions[opcode];

  get_operands(state);
  verb_state(state);
  ret = instruction.handler(state);
  if (strncmp(instruction.operation, "J", 1) != 0) /* Advance pc only if instruction is not a jump TODO: #pabo */
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

int                 i_prefix(t_cpustate *state)
{
  t_instruction     i = g_instructions_cb[state->memory.start[state->pc + 1]];
  printf("[+] Triggering CB instruction (%s)\n", i.operation);
  return g_instructions_cb[(int)state->op8].handler(state);
}

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
