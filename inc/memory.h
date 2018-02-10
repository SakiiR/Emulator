#ifndef MEMORY_H_
# define MEMORY_H_

# include <stdint.h>
# include "cpu.h"

uint8_t                 read_8(uint8_t *memory);
uint16_t                read_16(uint8_t *memory);
uint32_t                read_32(uint8_t *memory);

void                    write_bc(t_cpustate *state, uint16_t value);
void                    write_hl(t_cpustate *state, uint16_t value);

#endif /* !MEMORY_H_ */
