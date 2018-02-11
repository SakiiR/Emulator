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


void                    fill_bc(t_cpustate *state, uint16_t word)
{
  state->b = word & 0x00FF;
  state->c = word >> 8;
}

void                    fill_de(t_cpustate *state, uint16_t word)
{
  state->d = word & 0x00FF;
  state->e = word >> 8;
}

void                    fill_hl(t_cpustate *state, uint16_t word)
{
  state->h = word & 0x00FF;
  state->l = word >> 8;
}

uint8_t                 read_byte(t_cpustate *state, uint16_t address)
{
  return state->memory.start[address];
}

void                    write_byte(t_cpustate *state, uint16_t address, uint8_t byte)
{
  state->memory.start[address] = byte;
}


void                    dec_hl(t_cpustate *state)
{
  uint16_t              new_hl = get_hl(state) - 1;

  fill_hl(state, new_hl);
}

void                    inc_hl(t_cpustate *state)
{
  uint16_t              new_hl = get_hl(state) + 1;

  fill_hl(state, new_hl);
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


uint16_t                get_bc(t_cpustate *state)
{
  return state->c << 8 | state->b;
}

uint16_t                get_de(t_cpustate *state)
{
  return state->e << 8 | state->d;
}

uint16_t                get_hl(t_cpustate *state)
{
  return state->l << 8 | state->h;
}
