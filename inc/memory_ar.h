#ifndef MEMORY_AR_H_
# define MEMORY_AR_H_

# include <stdint.h>
# include "card.h"
# include "cpu.h"

typedef struct s_game   t_game;

void                    push_byte(t_game *game, uint8_t byte);
uint8_t                 pop_byte(t_game *game);
void                    push_word(t_game *game, uint16_t word);
uint16_t                pop_word(t_game *game);

uint8_t                 read_byte(t_game *game, uint16_t address);
uint16_t                read_word(t_game *game, uint16_t address);
void                    write_byte(t_game *game, uint16_t address, uint8_t byte);
void                    write_word(t_game *game, uint16_t address, uint16_t word);

#endif /* !MEMORY_AR_H_ */
