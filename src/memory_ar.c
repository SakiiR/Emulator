#include "memory_ar.h"

uint8_t                 read_8(uint8_t *memory)
{
  return memory[0];
}

uint16_t                read_16(uint8_t *memory)
{
  return memory[1] << 8 | memory[0];
}

uint32_t                read_32(uint8_t *memory)
{
  return memory[0] | (memory[1] << 8) | (memory[2] << 16) | (memory[3] << 24);
}

void                    push_byte(t_cpustate *state, uint8_t byte)
{
  state->memory.start[--state->sp] = byte;
}

uint8_t                 pop_byte(t_cpustate *state)
{
  return (state->memory.start[state->sp++]);
}

uint8_t                 read_byte(t_cpustate *state, uint16_t address)
{
  return state->memory.start[address];
}

void                    write_byte(t_cpustate *state, uint16_t address, uint8_t byte)
{
  state->memory.start[address] = byte;
}

void                    write_word(t_cpustate *state, uint16_t address, uint16_t word)
{
  write_byte(state, address, (uint8_t)(word & 0x00FF));
  write_byte(state, address + 1, (uint8_t)((word & 0xFF00) >> 8));
}

void                    push_word(t_cpustate *state, uint16_t word)
{
  push_byte(state, (word & 0xFF00) >> 8);
  push_byte(state, word & 0x00FF);
}

uint16_t                 pop_word(t_cpustate *state)
{
  return ((pop_byte(state) & 0x00FF) | (pop_byte(state) << 8));
}
