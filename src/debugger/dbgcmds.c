#include <string.h>
#include <stdlib.h>
#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "debugger/debugger.h"

t_dbgcmd                g_dbgcmds[] = {
    {"n",               &dbgcmd_next},
    {"next",            &dbgcmd_next},
    {"step",            &dbgcmd_next},
    {"q",               &dbgcmd_quit},
    {"quit",            &dbgcmd_quit},
    {"exit",            &dbgcmd_quit},
    {"b",               &dbgcmd_add_breakpoint},
    {"breakpoint",      &dbgcmd_add_breakpoint},
    {"d",               &dbgcmd_del_breakpoint},
    {"del",             &dbgcmd_del_breakpoint},
    {"delete",          &dbgcmd_del_breakpoint},
    {"c",               &dbgcmd_continue},
    {"continue",        &dbgcmd_continue},
    {"r",               &dbgcmd_reset},
    {"reset",           &dbgcmd_reset},
    {NULL,              NULL},
};

int                     dbgcmd_next(t_game *game, const char **argv)
{
  (void)argv;
  cpu_step(&game->state, 1);
  return RETURN_SUCCESS;
}

int                     dbgcmd_quit(t_game *game, const char **argv)
{
  (void)game;
  (void)argv;
  printf("[~] Exiting\n");
  return RETURN_FAILURE;
}

static char             parse_address(char *arg, uint16_t *address)
{
  char                  *s = arg;

  if (arg == NULL)
    return RETURN_SUCCESS;
  if (strncmp(arg, "0x", 2) == 0)
    s = &arg[2];
  if (strlen(s) != 4)
  {
    fprintf(stderr, "[-] Failed to parse '%s' as uint16_t value\n", arg);
    return RETURN_FAILURE;
  }
  *address = strtol(s, NULL, 16);
  printf("[~] Fixed breakpoint at address 0x%04x\n", *address);
  return RETURN_SUCCESS;  
}

int                     dbgcmd_add_breakpoint(t_game *game, const char **argv)
{
  uint16_t              address;

  if (!(argv && argv[0] && argv[1]))
    return RETURN_SUCCESS;
  if (parse_address((char *)argv[1], &address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  if (add_breakpoint(&game->dbg.breakpoints, address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  return RETURN_SUCCESS;
}


int                     dbgcmd_del_breakpoint(t_game *game, const char **argv)
{
  uint16_t              address;

  if (!(argv && argv[0] && argv[1]))
    return RETURN_SUCCESS;
  if (parse_address((char *)argv[1], &address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  if (delete_breakpoint(&game->dbg.breakpoints, address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  return RETURN_SUCCESS;
}

static char             should_break(t_breakpoint *breakpoints, uint16_t address)
{
  t_breakpoint          *it = breakpoints;

  while (it)
  {
    if (it->address == address)
      return RETURN_SUCCESS;
    it = it->next;
  }
  return RETURN_FAILURE;
}

int                     dbgcmd_continue(t_game *game, const char **argv)
{
  (void)argv;
  while (1)  
  {
    if (should_break(game->dbg.breakpoints, game->state.pc) == RETURN_SUCCESS)
      break;
    cpu_step(&game->state, 0);
  }
  cpu_step(&game->state, 1);
  return RETURN_SUCCESS;
}

int                     dbgcmd_reset(t_game *game, const char **argv)
{
  (void)argv;
  if (init_cpu(&game->state, &game->card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  cpu_step(&game->state, 1);
  return RETURN_SUCCESS;
}
