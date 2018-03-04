#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "resource.h"
#include "utils.h"
#include "instructions.h"
#include "cpu.h"
#include "game.h"
#include "debugger/debugger.h"

t_dbgcmd                g_dbgcmds[] = {
  {"help",            &dbgcmd_help,             "Display help message"},
  {"n",               &dbgcmd_next,             "Step to next instruction and display the status"},
  {"next",            &dbgcmd_next,             "Step to next instruction and display the status"},
  {"step",            &dbgcmd_next,             "Step to next instruction and display the status"},
  {"q",               &dbgcmd_quit,             "Quit the gameboy emulator"},
  {"quit",            &dbgcmd_quit,             "Quit the gameboy emulator"},
  {"exit",            &dbgcmd_quit,             "Quit the gameboy emulator"},
  {"b",               &dbgcmd_add_breakpoint,   "Add a breakpoint"},
  {"breakpoint",      &dbgcmd_add_breakpoint,   "Add a breakpoint"},
  {"breakpoints",     &dbgcmd_list_breakpoints, "List all breakpoints"},
  {"blist",           &dbgcmd_list_breakpoints, "List all breakpoints"},
  {"d",               &dbgcmd_del_breakpoint,   "Delete a breakpoint"},
  {"del",             &dbgcmd_del_breakpoint,   "Delete a breakpoint"},
  {"delete",          &dbgcmd_del_breakpoint,   "Delete a breakpoint"},
  {"c",               &dbgcmd_continue,         "Continue until a breakpoint is met"},
  {"continue",        &dbgcmd_continue,         "Continue until a breakpoint is met"},
  {"r",               &dbgcmd_reset,            "Reset the gameboy"},
  {"reset",           &dbgcmd_reset,            "Reset the gameboy"},
  {"x",               &dbgcmd_x,                "Display N byte from the gameboy memory"},
  {"vram",            &dbgcmd_dump_vram,        "Dump video memory to file"},
  {"tiles",           &dbgcmd_dump_tiles,       "Dump tiles to stdout"},
  {"i",               &dbgcmd_i,                "Execute n instructions"},
  {NULL,              NULL,                     NULL},
};

static void             gameboy_step(t_game *game, char verbose)
{
  cpu_step(game, verbose);
  gpu_step(game);
  timer_step(game);
  interrupts_step(game);
}

static unsigned int     tokens_length(const char **tokens)
{
  unsigned int          i;

  for (i = 0 ; tokens && tokens[i] ; ++i)
    ;
  return i;
}

int                     dbgcmd_help(t_game *game, const char **argv)
{
  (void)game;
  (void)argv;
  printf("[~] Available commands: \n");
  for (unsigned int i = 0 ; g_dbgcmds[i].command ; ++i)
    printf("%20s - %s\n", g_dbgcmds[i].command, g_dbgcmds[i].description);
  return RETURN_SUCCESS;
}

int                     dbgcmd_next(t_game *game, const char **argv)
{
  (void)argv;
  gameboy_step(game, 1);
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
  return RETURN_SUCCESS;
}

int                     dbgcmd_add_breakpoint(t_game *game, const char **argv)
{
  uint16_t              address;

  if (!(argv && argv[0] && argv[1]))
    return RETURN_SUCCESS;
  if (parse_address((char *)argv[1], &address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  printf("[~] Fixed breakpoint at address 0x%04x\n", address);
  if (add_breakpoint(&game->dbg.breakpoints, address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  return RETURN_SUCCESS;
}

int                     dbgcmd_list_breakpoints(t_game *game, const char **argv)
{
  t_breakpoint          *it = game->dbg.breakpoints;
  t_instruction         *instruction = NULL;

  (void)argv;
  printf("[~] Breakpoint list:\n");
  while (it)
  {
    instruction = decode_instruction(game, it->address);
    printf("\t at address: 0x%04x -> %s \n", it->address, instruction->operation);
    it = it->next;
  }
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
    gameboy_step(game, 0);
  }
  gameboy_step(game, 1);
  return RETURN_SUCCESS;
}

int                     dbgcmd_reset(t_game *game, const char **argv)
{
  (void)argv;
  if (init_cpu(&game->state, &game->card) == RETURN_FAILURE)
    return RETURN_FAILURE;
  gameboy_step(game, 1);
  return RETURN_SUCCESS;
}

static void             hex_dump(const uint8_t *memory, uint16_t address, unsigned long count)
{
  uint8_t              i = 0;
  uint8_t              j = 0;

  while (i < count)
  {
    printf("0x%04x: ", address + i);
    for (j = i ; j < i + 16 ; j += 2)
    {
      printf("%02x", memory[address + j]);
      printf("%02x ", memory[address + j + 1]);
    }
    for (j = i ; j < i + 16 ; ++j)
      printf("%c", isprint(memory[address + j]) ? memory[address + j]: '.');
    printf("\n");
    i += j;
  }
}

int                     dbgcmd_dump_vram(t_game *game, const char **argv)
{
  (void)argv;
  dump_vram(game);
  return RETURN_SUCCESS;
}

int                     dbgcmd_dump_tiles(t_game *game, const char **argv)
{
  unsigned int          argc = tokens_length(argv);
  size_t                n = 0;
  FILE                  *out = stdout;

  if (!(argc > 1 && atoi(argv[1]) >= 0))
  {
    printf("[~] tiles <count (>= 1)> <out>\n");
    return RETURN_SUCCESS;
  }
  n = (size_t)atoi(argv[1]);
  if (argc > 2)
  {
    if ((out = fopen(argv[2], "w")) == NULL)
    {
      fprintf(stderr, "[-] Failed to open '%s' for writing\n", argv[2]);
      out = stdout;
    }
  }
  dump_tiles(game, n, out);
  if (argc > 2)
    fclose(out);
  return RETURN_SUCCESS;
}

int                     dbgcmd_i(t_game *game, const char **argv)
{
  unsigned int          argc = tokens_length(argv);
  unsigned long long    count = 0;

  if (argc < 2)
  {
    printf("[~] i <count (>= 1)>\n");
    return RETURN_SUCCESS;
  }
  count = strtoull(argv[1], NULL, 10);
  for (unsigned long long i = 0 ; i < count - 1; ++i)
    gameboy_step(game, 0);
  gameboy_step(game, 1);
  return RETURN_SUCCESS;
}

int                     dbgcmd_x(t_game *game, const char **argv)
{
  unsigned int          argc = tokens_length(argv);
  unsigned long         count = 0;
  uint16_t              address = 0;

  if (argc < 3)
  {
    fprintf(stderr, "[~] x <count> <addr>\n");
    return RETURN_SUCCESS;
  }
  if ((count = strtoul(argv[1], NULL, 10)) == 0)
  {
    fprintf(stderr, "[~] x <count> <addr>\ncount should be > 0\n");
    return RETURN_SUCCESS;
  }
  if (parse_address((char *)argv[2], &address) == RETURN_FAILURE)
    return RETURN_SUCCESS;
  hex_dump(game->state.memory.start, address, count);
  return RETURN_SUCCESS;
}
