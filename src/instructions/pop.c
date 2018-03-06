#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_pop_af(t_game *game)
{
	game->state.af = pop_word(game);
    return RETURN_SUCCESS;
}

int                 i_pop_bc(t_game *game)
{
	game->state.bc = pop_word(game);
    return RETURN_SUCCESS;
}

int                 i_pop_de(t_game *game)
{
	game->state.de = pop_word(game);
    return RETURN_SUCCESS;
}

int                 i_pop_hl(t_game *game)
{
	game->state.hl = pop_word(game);
    return RETURN_SUCCESS;
}
