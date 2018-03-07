#ifndef GAME_H_
# define GAME_H_

# include "cpu.h"
# include "card.h"
# include "opts.h"
# include "video/video.h"
# include "debugger/debugger.h"
# include "interrupts.h"
# include "timer.h"

typedef struct      s_game
{
  t_cpustate        state;
  t_opts            options;
  t_card            card;
  t_dbg             dbg;
  t_interrupts      interrupts;
  t_timer           timer;
  struct s_gpu      gpu;
}                   t_game;

int                 game_loop(t_game *game);

#endif /* !GAME_H_ */
