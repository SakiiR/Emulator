#ifndef DEBUGGER_H_
# define DEBUGGER_H_

# include "debugger/breakpoint.h"

typedef struct s_game   t_game;

typedef struct          s_dbgcmd
{
  char                  *command;
  int                   (*handler)(t_game *game, const char **argv);
  char                  *description;
}                       t_dbgcmd;

typedef struct          s_dbg
{
  struct s_breakpoint   *breakpoints;  
  t_dbgcmd              *last_command;
}                       t_dbg;

extern t_dbgcmd	        g_dbgcmds[];

int                     debugger(t_game *game);

int                     dbgcmd_help(t_game *game, const char **argv);
int                     dbgcmd_next(t_game *game, const char **argv);
int                     dbgcmd_quit(t_game *game, const char **argv);
int                     dbgcmd_add_breakpoint(t_game *game, const char **argv);
int                     dbgcmd_list_breakpoints(t_game *game, const char **argv);
int                     dbgcmd_del_breakpoint(t_game *game, const char **argv);
int                     dbgcmd_continue(t_game *game, const char **argv);
int                     dbgcmd_reset(t_game *game, const char **argv);
int                     dbgcmd_x(t_game *game, const char **argv);

#endif /* DEBUGGER_H_ */
