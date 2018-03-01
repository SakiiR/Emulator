#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_push_af(t_game *game)
{
    push_word(&game->state, game->state.af);
    return RETURN_SUCCESS;
}

int                 i_push_bc(t_game *game)
{
    push_word(&game->state, game->state.bc);
    return RETURN_SUCCESS;
}

int                 i_push_de(t_game *game)
{
    push_word(&game->state, game->state.de);
    return RETURN_SUCCESS;
}

int                 i_push_hl(t_game *game)
{
    push_word(&game->state, game->state.hl);
    return RETURN_SUCCESS;
}
