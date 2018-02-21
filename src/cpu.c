#include <stdio.h>
#include <unistd.h>
#include "instructions.h"
#include "cpu.h"
#include "resource.h"
#include "card.h"

static void      init_registers(t_cpustate *state)
{
  state->af	= 0x01b0;
  state->bc	= 0x0013;
  state->de	= 0x00d8;
  state->hl	= 0x014d;
  state->sp	= 0xfffe;
  state->pc	= 0x0100; /* Cartridge entry point */
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

/**
 * Launch the loop()
 */
int             emulate(t_card *card)
{
  t_cpustate    state;
  uint8_t       opcode;

  if (init_memory(&state.memory, card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  init_registers(&state);
  init_hregisters(&state);
  while (1)
  {
    opcode = state.memory.start[state.pc];
    if (search_instruction(opcode, &state) == RETURN_FAILURE)
      return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
