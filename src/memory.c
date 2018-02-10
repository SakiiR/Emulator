#include "cpu.h"
#include "memory.h"

uint16_t                read_16(uint8_t *memory)
{
  return memory[1] << 8 | memory[0];
}

uint8_t                 read_8(uint8_t *memory)
{

  return memory[0];
}

uint32_t                read_32(uint8_t *memory)
{
  return memory[0] | (memory[1] << 8) | (memory[2] << 16) | (memory[3] << 24);
}

/**
 * Write value to registers b and c
 */
void                    write_bc(t_cpustate *state, uint16_t value)
{
  state->b = value & 0x00ff;
  state->c = value & 0xff00 >> 8;
}

/**
 * Write value to registers h and l
 */
void                    write_hl(t_cpustate *state, uint16_t value)
{
  state->h = value & 0x00ff;
  state->l = value & 0xff00 >> 8;
}
