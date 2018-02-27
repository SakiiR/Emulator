#ifndef BREAKPOINT_H_
# define BREAKPOINT_H_

# include <stdint.h>

typedef struct          s_breakpoint
{
  struct s_breakpoint   *next;
  struct s_breakpoint   *prev;
  uint16_t              address;
}                       t_breakpoint;

char                    init_breakpoints(t_breakpoint **breakpoints);
char                    add_breakpoint(t_breakpoint **breakpoints, uint16_t address);
char                    delete_breakpoint(t_breakpoint **breakpoints, uint16_t address);

#endif /* !BREAKPOINT_H_ */

