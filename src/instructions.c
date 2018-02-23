#include <string.h>
#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "register.h"
#include "memory_ar.h"


static void         get_operands(t_cpustate *state)
{
  state->op16 = (short)read_16(&state->memory.start[state->pc + 1]);
}

static void         dump_memory(uint8_t *memory, unsigned int n)
{
  unsigned int      i = 0;

  for (i = 0 ; i < n ; ++i)
    printf("%02x ", memory[i]);
  printf("\n");
}
static void         verb_state(t_cpustate *state)
{
  t_instruction     instruction = g_instructions[state->memory.start[state->pc]];

  printf("A: %02x F: %02x (AF: %04x)                       \n", state->a, state->f, state->af);
  printf("B: %02x C: %02x (BC: %04x)                       \n", state->b, state->c, state->bc);
  printf("D: %02x E: %02x (DE: %04x)                       \n", state->d, state->e, state->de);
  printf("H: %02x L: %02x (HL: %04x)                       \n", state->h, state->l, state->hl);
  printf("PC: %04x SP: %04x                                \n", state->pc, state->sp);
  printf("OP8: %02X  OP16: %04x                            \n", (uint8_t)state->op8, (uint16_t)state->op16);
  printf("MEM: ");
  dump_memory(&state->memory.start[state->pc], 10);
  printf("[%c%c%c%c]                                       \n",
         (get_Z(&state->f) ? 'Z': '-'),
         (get_N(&state->f) ? 'N': '-'),
         (get_H(&state->f) ? 'H': '-'),
         (get_C(&state->f) ? 'C': '-')
         );
  printf("00:%04x:  00	%s                                 \n", state->pc, instruction.operation);
}

int                 search_instruction(uint8_t opcode, t_cpustate *state, t_opts *options)
{
  int               ret = RETURN_SUCCESS;
  t_instruction     instruction = g_instructions[opcode];

  get_operands(state);
  if (options->verbose)
    verb_state(state);
  state->pc += instruction.size;
  ret = instruction.handler(state);
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

