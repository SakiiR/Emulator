#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_cp_a(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.a;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_b(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.b;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_c(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.c;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_d(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.d;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_e(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.e;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_h(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.h;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_l(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.l;

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_hl(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = read_byte(&game->state, game->state.hl);

    if (op1 < op2)
      set_C(&game->state.f);
    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);
    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_sharp(t_game *game)
{
    uint8_t         op1 = game->state.a;
    uint8_t         op2 = game->state.op8;

    if (op1 < op2)
      set_C(&game->state.f);

    if (op1 == op2)
      set_Z(&game->state.f);
    else
      reset_Z(&game->state.f);

    set_N(&game->state.f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}
