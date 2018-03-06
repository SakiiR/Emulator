#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"

static void         rst(t_game *game, uint8_t address)
{
  push_word(game, game->state.pc);
  game->state.pc = address;
}

int                 i_rst_00(t_game *game)
{
    rst(game, 0x00);
    return RETURN_SUCCESS;
}

int                 i_rst_08(t_game *game)
{
    rst(game, 0x08);
    return RETURN_SUCCESS;
}

int                 i_rst_10(t_game *game)
{
    rst(game, 0x10);
    return RETURN_SUCCESS;
}

int                 i_rst_18(t_game *game)
{
    rst(game, 0x18);
    return RETURN_SUCCESS;
}

int                 i_rst_20(t_game *game)
{
    rst(game, 0x20);
    return RETURN_SUCCESS;
}

int                 i_rst_28(t_game *game)
{
    rst(game, 0x28);
    return RETURN_SUCCESS;
}

int                 i_rst_30(t_game *game)
{
    rst(game, 0x30);
    return RETURN_SUCCESS;
}

int                 i_rst_38(t_game *game)
{
    rst(game, 0x38);
    return RETURN_SUCCESS;
}
