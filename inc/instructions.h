#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# include "cpu.h"

typedef struct      s_instruction
{
  unsigned int      opcode;
  int               (*handler)(struct s_8080state *state);
}                   t_instruction;

int          unimplemented_instruction(t_8080state *state);

#endif /* !INSTRUCTIONS_H_ */
