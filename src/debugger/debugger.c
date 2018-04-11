#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "debugger/debugger.h"
#include "resource.h"
#include "game.h"
#include "cpu.h"

#define SIGNAL          (SIGINT)

struct s_game           *g_game = NULL;

static void             free_split(const char **tab)
{
  unsigned int          i = 0;

  for (i = 0 ; tab && tab[i] ; ++i)
    free((char *)tab[i]);
  free(tab);
}

static char             *strip_eol(char *string)
{
  unsigned int          index = 0;

  if (string == NULL)
    return NULL;
  index = strlen(string) - 1;
  if (string[index] == '\n')
    string[index] = 0;
  return string;
}

static const char       **split(char *string, char *delim)
{
  const char            **tab = NULL;   
  char                  *token = NULL;
  size_t                size = 0;

  if (string == NULL)
    return NULL;
  if ((tab = malloc(sizeof(*tab) * 1 + 1)) == NULL)
    return NULL;
  token = strtok(string, delim);
  while (token != NULL)
  {
    if ((tab[size] = strdup(token)) == NULL)
      return NULL;
    tab[size] = strip_eol((char *)tab[size]);
    if ((tab = realloc(tab, (sizeof(*tab) * (size + 1)) + 1)) == NULL)
      return NULL;
    token = strtok(NULL, delim);
    ++size;
  }
  tab[size] = 0;
  return tab;
}

static int              parse_command(t_game *game, char *line)
{
  const char            **argv = NULL;
  unsigned int          i = 0;

  if ((argv = split(line, " ")) == NULL)
    return RETURN_FAILURE;
  for (i = 0 ; g_dbgcmds[i].command ; ++i)
  {
    if (strcmp(g_dbgcmds[i].command, argv[0]) == 0)
    {
      game->dbg.last_command = &g_dbgcmds[i];
      if (g_dbgcmds[i].handler != NULL)
        if (g_dbgcmds[i].handler(game, argv) == RETURN_FAILURE)
          return RETURN_FAILURE;
      break;
    }
  }
  if (argv && strlen(argv[0]) == 0)
  {
    if (game->dbg.last_command != NULL)
      if (game->dbg.last_command->handler(game, NULL) == RETURN_FAILURE)
        return RETURN_FAILURE;
  }
  free_split(argv);
  return RETURN_SUCCESS;
}

static void             init_dbg(t_game *game)
{
  init_breakpoints(&game->dbg.breakpoints);
  game->dbg.last_command = NULL;
}


static int              debug_step(t_game *game)
{
  size_t                size;
  char                  *line = NULL;
  t_game                *current_game = game;

  printf("> ");
  if (getline(&line, &size, stdin) == -1)
  {
    fprintf(stderr, "[-] Failed to read stdin, Exiting\n");
    return RETURN_FAILURE;
  }
  if (current_game == NULL)
    current_game = g_game;
  if (parse_command(current_game, line) == RETURN_FAILURE)
    return RETURN_FAILURE;
  return RETURN_SUCCESS;
}

static void             signal_handler(int sig)
{
  if (sig == SIGNAL)
  {
    signal(SIGNAL, &signal_handler);
    printf("\n");
    debug_step(NULL);
  }
}

int                     debugger(t_game *game)
{
  if (init_cpu(&game->state, &game->card) == RETURN_FAILURE) 
    return RETURN_FAILURE;
  init_gpu(&game->gpu);
  init_timer(&game->timer);
  init_interrupts(&game->interrupts);
  init_dbg(game);
  g_game = game;
  signal(SIGNAL, &signal_handler);
  while (1)
    if (debug_step(game) == RETURN_FAILURE)
      return RETURN_FAILURE;
  return RETURN_SUCCESS;
}
