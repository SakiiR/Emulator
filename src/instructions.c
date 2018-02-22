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
  uint16_t          oldpc = 0;
  t_instruction     instruction = g_instructions[opcode];

  get_operands(state);
  if (options->verbose)
    verb_state(state);
  oldpc = state->pc;
  ret = instruction.handler(state);
  if (oldpc == state->pc)
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

int                 i_daa(t_cpustate *state)
{
  if (get_H(&state->f) || (state->a & 0x0F) > 0x9)
    state->a += 6;
  if (get_C(&state->f) || (state->a & 0xF0) > 0x90)
  {
    set_C(&state->f);
    state->a += 96;
  }
  else
    reset_C(&state->f);
  zero_flag_check(&state->f, state->a);
  reset_H(&state->f);
  return RETURN_SUCCESS;
}

int                 i_cpl(t_cpustate *state)
{
  state->a = ~state->a;
  reset_N(&state->f);
  reset_H(&state->f);
  get_C(&state->f) ? reset_C(&state->f) : set_C(&state->f);
  return RETURN_SUCCESS;
}
