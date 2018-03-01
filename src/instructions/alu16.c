#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"


int                 i_add16_hl_bc(t_game *game)
{
    uint16_t        op1 = game->state.hl;
    uint16_t        op2 = game->state.bc;

    game->state.hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_de(t_game *game)
{
    uint16_t        op1 = game->state.hl;
    uint16_t        op2 = game->state.de;

    game->state.hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_hl(t_game *game)
{
    uint16_t        op1 = game->state.hl;
    uint16_t        op2 = game->state.hl;

    game->state.hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_sp(t_game *game)
{
    uint16_t        op1 = game->state.hl;
    uint16_t        op2 = game->state.sp;

    game->state.hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_inc_d_bc(t_game *game)
{
    ++game->state.bc;
    return RETURN_SUCCESS;
}

int                 i_inc_d_de(t_game *game)
{
    ++game->state.de;
    return RETURN_SUCCESS;
}

int                 i_inc_d_hl(t_game *game)
{
    ++game->state.hl;
    return RETURN_SUCCESS;
}

int                 i_inc_d_sp(t_game *game)
{
    ++game->state.sp;
    return RETURN_SUCCESS;
}

int                 i_dec_d_bc(t_game *game)
{
    --game->state.bc;
    return RETURN_SUCCESS;
}

int                 i_dec_d_de(t_game *game)
{
    --game->state.de;
    return RETURN_SUCCESS;
}

int                 i_dec_d_hl(t_game *game)
{
    --game->state.hl;
    return RETURN_SUCCESS;
}

int                 i_dec_d_sp(t_game *game)
{
    --game->state.sp;
    return RETURN_SUCCESS;
}
