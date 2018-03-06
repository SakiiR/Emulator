#include "game.h"
#include "memory_ar.h"

void                    push_byte(t_game *game, uint8_t byte)
{
  game->state.memory.start[--game->state.sp] = byte;
}

uint8_t                 pop_byte(t_game *game)
{
  return (game->state.memory.start[game->state.sp++]);
}

void                    push_word(t_game *game, uint16_t word)
{
  push_byte(game, (word & 0xFF00) >> 8);
  push_byte(game, word & 0x00FF);
}

uint16_t                pop_word(t_game *game)
{
  return ((pop_byte(game) & 0x00FF) | (pop_byte(game) << 8));
}

uint8_t                 read_byte(t_game *game, uint16_t address)
{
  /* Check for access control stat mode */
  return game->state.memory.start[address];
}

uint16_t                read_word(t_game *game, uint16_t address)
{
  uint8_t               a = read_byte(game, address);
  uint8_t               b = read_byte(game, address + 1);

  return b << 8 | a;
}

void                    write_byte(t_game *game, uint16_t address, uint8_t byte)
{
  game->state.memory.start[address] = byte;
}

void                    write_word(t_game *game, uint16_t address, uint16_t word)
{
  write_byte(game, address, (uint8_t)(word & 0x00FF));
  write_byte(game, address + 1, (uint8_t)((word & 0xFF00) >> 8));
}
