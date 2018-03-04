#include <string.h>
#include <stdio.h>
#include "instructions.h"
#include "cpu.h"
#include "game.h"
#include "resource.h"
#include "register.h"
#include "memory_ar.h"


int                         unimplemented_instruction(t_game *game)
{
  t_instruction             *instruction = game->state.instruction;

  fprintf(stderr, 
          "[-] Unimplemented Instruction at 0x%04x (%s) (0x%02x)\n",
          game->state.old_pc,
          instruction->operation,
          game->state.memory.start[game->state.old_pc]
         );
  return RETURN_FAILURE;
}

t_instruction               *decode_instruction(t_game *game, uint16_t pc)
{
  return &g_instructions[game->state.memory.start[pc]];
}

int                         i_prefix(t_game *game)
{
  t_instruction     i = g_instructions_cb[game->state.memory.start[game->state.pc + 1]];

  game->state.pc += i.size;
  return g_instructions_cb[(int)game->state.op8].handler(game);
}


