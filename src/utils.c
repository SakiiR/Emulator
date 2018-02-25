#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "resource.h"
#include "game.h"
#include "utils.h"

int                         dump_memory(t_game *game)
{
  int                       outfile = 0;
  unsigned int              i = 0;

  if ((outfile = open(DUMP_OUTFILE, MODE_OUTFILE, PERM_OUTFILE)) == -1)
  {
    fprintf(stderr, "[-] MemoryDump: Failed to open outfile '%s' for writing..\n", DUMP_OUTFILE);
    return RETURN_FAILURE;  
  }
  for (i = 0 ; i < 0xFFFF ; ++i)
    (void)write(outfile, &game->state.memory.start[i], 1);
  printf("[+] Dumped memory to file '%s'\n", DUMP_OUTFILE);
  close(outfile);
  return RETURN_SUCCESS;
}

int                         dump_vram(t_game *game)
{
  int                       outfile = 0;
  unsigned int              i = 0;

  if ((outfile = open(DUMP_OUTFILE, MODE_OUTFILE, PERM_OUTFILE)) == -1)
  {
    fprintf(stderr, "[-] MemoryDump: Failed to open outfile '%s' for writing..\n", DUMP_OUTFILE);
    return RETURN_FAILURE;  
  }
  for (i = 0x8000  ; i < 0x9FFF ; ++i)
    (void)write(outfile, &game->state.memory.start[i], 1);
  printf("[+] Dumped vram to file '%s'\n", DUMP_OUTFILE);
  close(outfile);
  return RETURN_SUCCESS;
}
