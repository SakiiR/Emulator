#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "resource.h"
#include "game.h"
#include "video.h"
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
  for (i = VRAM_START  ; i < VRAM_END ; ++i)
    (void)write(outfile, &game->state.memory.start[i], 1);
  /* printf("[+] Dumped vram to file '%s'\n", DUMP_OUTFILE); */
  close(outfile);
  return RETURN_SUCCESS;
}

void                        dump_tiles(t_game *game, size_t n, FILE *out)
{
  size_t                    displayed = 0;

  for (unsigned int i = VRAM_START; displayed < n && i < 0x8fff ; i += 16)
  {
    fprintf(out, "--- Tile %10lu ---\n", displayed);
    dump_tile(&game->state.memory.start[i], out);
    fprintf(out, "---------------\n");
    ++displayed;
  }
  for (unsigned int i = 0x8800; displayed < n && i < 0x97ff ; i += 16)
  {
    fprintf(out, "--- Tile %10lu ---\n", displayed);
    dump_tile(&game->state.memory.start[i], out);
    fprintf(out, "---------------\n");
    ++displayed;
  }
}

void                        dump_tile(uint8_t *tile, FILE *out)
{
  static char               *cli_palette[] = {
    "  ",
    "░░",
    "▒▒",
    "▓▓",
  };
  for (int i = 0 ; i < 16 ; i += 2)
  {
    uint8_t byte2 = tile[i];
    uint8_t byte1 = tile[i + 1];
    for (int j = 8 ; j >= 0 ; --j)
    {
      uint8_t value = (GET_N_BIT(byte1, j) << 1) + GET_N_BIT(byte2, j);
      fprintf(out, "%s", cli_palette[value]);
    }
    fprintf(out, "\n");
  }
}
