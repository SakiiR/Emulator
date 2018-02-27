#include <SDL/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include "opts.h"
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "card.h"
#include "memory_ar.h"

static void      init_registers(t_cpustate *state)
{
  state->af	= 0x01b0;
  state->bc	= 0x0013;
  state->de	= 0x00d8;
  state->hl	= 0x014d;
  state->sp	= 0xfffe;
  state->pc	= 0x0100; /* Cartridge entry point */
  state->op8 = 0x00;
  state->op16 = 0x0000;
}

static void      init_hregisters(t_cpustate *state)
{
  state->hregisters.TIMA   = state->memory.start + 0xff05; //TODO: check quand je serai reveillé (2.7.1 GameBoy CPU Manual)
  state->hregisters.TMA    = state->memory.start + 0xff06;
  state->hregisters.TAC    = state->memory.start + 0xff07;
  state->hregisters.NR10   = state->memory.start + 0xff10;
  state->hregisters.NR11   = state->memory.start + 0xff11;
  state->hregisters.NR12   = state->memory.start + 0xff12;
  state->hregisters.NR14   = state->memory.start + 0xff14;
  state->hregisters.NR21   = state->memory.start + 0xff16;
  state->hregisters.NR22   = state->memory.start + 0xff17;
  state->hregisters.NR24   = state->memory.start + 0xff19;
  state->hregisters.NR30   = state->memory.start + 0xff1a;
  state->hregisters.NR31   = state->memory.start + 0xff1b;
  state->hregisters.NR32   = state->memory.start + 0xff1c;
  state->hregisters.NR33   = state->memory.start + 0xff1e;
  state->hregisters.NR41   = state->memory.start + 0xff20;
  state->hregisters.NR42   = state->memory.start + 0xff21;
  state->hregisters.NR43   = state->memory.start + 0xff22;
  state->hregisters.NR50   = state->memory.start + 0xff24;
  state->hregisters.NR51   = state->memory.start + 0xff25;
  state->hregisters.NR52   = state->memory.start + 0xff26;
  state->hregisters.LCDC   = state->memory.start + 0xff40;
  state->hregisters.SCY    = state->memory.start + 0xff42;
  state->hregisters.SCX    = state->memory.start + 0xff43;
  state->hregisters.LYC    = state->memory.start + 0xff45;
  state->hregisters.BGP    = state->memory.start + 0xff47;
  state->hregisters.OBP0   = state->memory.start + 0xff48;
  state->hregisters.OBP1   = state->memory.start + 0xff49;
  state->hregisters.WY     = state->memory.start + 0xff4a;
  state->hregisters.WX     = state->memory.start + 0xff4b;
  state->hregisters.IE     = state->memory.start + 0xffff;

  *state->hregisters.TIMA  = 0x00;
  *state->hregisters.TMA   = 0x00;
  *state->hregisters.TAC   = 0x00;
  *state->hregisters.NR10  = 0x80;
  *state->hregisters.NR11  = 0xbf;
  *state->hregisters.NR12  = 0xf3;
  *state->hregisters.NR14  = 0xbf;
  *state->hregisters.NR21  = 0x3f;
  *state->hregisters.NR22  = 0x00;
  *state->hregisters.NR24  = 0xbf;
  *state->hregisters.NR30  = 0x7f;
  *state->hregisters.NR31  = 0xff;
  *state->hregisters.NR32  = 0x9f;
  *state->hregisters.NR33  = 0xbf;
  *state->hregisters.NR41  = 0xff;
  *state->hregisters.NR42  = 0x00;
  *state->hregisters.NR43  = 0x00;
  *state->hregisters.NR50  = 0x77;
  *state->hregisters.NR51  = 0xf3;
  *state->hregisters.NR52  = 0xf1;
  *state->hregisters.LCDC  = 0x91;
  *state->hregisters.SCY   = 0x00;
  *state->hregisters.SCX   = 0x00;
  *state->hregisters.LYC   = 0x00;
  *state->hregisters.BGP   = 0xfc;
  *state->hregisters.OBP0  = 0xff;
  *state->hregisters.OBP1  = 0xff;
  *state->hregisters.WY    = 0x00;
  *state->hregisters.WX    = 0x00;
  *state->hregisters.IE    = 0x00;
}

static void         dump_memory(uint8_t *memory, unsigned int n)
{
  unsigned int      i = 0;

  for (i = 0 ; i < n ; ++i)
    printf("%02x ", memory[i]);
  printf("\n");
}

void                verb_state(t_cpustate *state)
{
  char              operation[32];
  t_instruction     *instruction = state->instruction;

  if (instruction->size == 2)
    sprintf(operation, instruction->operation, (uint8_t)state->op8);
  else if (instruction->size == 3)
    sprintf(operation, instruction->operation, (uint8_t)state->op16);
  else 
    strcpy(operation, instruction->operation);
  printf("A: %02x F: %02x (AF: %04x)                       \n", state->a, state->f, state->af);
  printf("B: %02x C: %02x (BC: %04x)                       \n", state->b, state->c, state->bc);
  printf("D: %02x E: %02x (DE: %04x)                       \n", state->d, state->e, state->de);
  printf("H: %02x L: %02x (HL: %04x)                       \n", state->h, state->l, state->hl);
  printf("PC: %04x SP: %04x                                \n", state->pc, state->sp);
  printf("OP8: %02X  OP16: %04x                            \n", (uint8_t)state->op8, (uint16_t)state->op16);
  printf("MEM: ");
  dump_memory(&state->memory.start[state->pc], 10);
  printf(
         "[%c%c%c%c]                                       \n",
         (get_Z(&state->f) ? 'Z': '-'),
         (get_N(&state->f) ? 'N': '-'),
         (get_H(&state->f) ? 'H': '-'),
         (get_C(&state->f) ? 'C': '-')
        );
  printf("00:%04x:  00	%s                                 \n", state->pc, operation);
  printf("\n");
}

static void         get_operands(t_cpustate *state)
{
  state->op16 = (short)read_16(&state->memory.start[state->pc + 1]);
}

int                 init_cpu(t_cpustate *state, t_card *card)
{
  if (init_memory(&state->memory, card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  init_registers(state);
  init_hregisters(state);
  return RETURN_SUCCESS;
}

/**
 * One CPU step/stage 
 */
int                 cpu_step(t_cpustate *state, char verbose)
{
  uint8_t           opcode = state->memory.start[state->pc];

  get_operands(state);
  state->instruction = &g_instructions[opcode];
  if (verbose)
    verb_state(state);
  state->old_pc = state->pc;
  state->pc += state->instruction->size;
  state->instruction->handler(state);
  return RETURN_SUCCESS;
}
