#ifndef MEMORY_AR_H_
# define MEMORY_AR_H_

# include <stdint.h>
# include "card.h"
# include "cpu.h"

void                    push_byte(t_cpustate *state, uint8_t byte);
uint8_t                 pop_byte(t_cpustate *state);
void                    push_word(t_cpustate *state, uint16_t word);
uint16_t                pop_word(t_cpustate *state);

uint8_t                 read_byte(t_cpustate *state, uint16_t address);
void                    write_byte(t_cpustate *state, uint16_t address, uint8_t byte);
void                    write_word(t_cpustate *state, uint16_t address, uint16_t word);

void                    fill_bc(t_cpustate *state, uint16_t word);
void                    fill_de(t_cpustate *state, uint16_t word);
void                    fill_hl(t_cpustate *state, uint16_t word);

void                    dec_hl(t_cpustate *state);
void                    inc_hl(t_cpustate *state);

uint16_t                get_bc(t_cpustate *state);
uint16_t                get_de(t_cpustate *state);
uint16_t                get_hl(t_cpustate *state);

#endif /* !MEMORY_AR_H_ */
