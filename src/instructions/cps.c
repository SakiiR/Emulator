#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"


int                 i_cp_a(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->a;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_b(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->b;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_c(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->c;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_d(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->d;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_e(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->e;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_h(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->h;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_l(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->l;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_hl(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = read_byte(state, state->hl);

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}

int                 i_cp_sharp(t_cpustate *state)
{
    uint8_t         op1 = state->a;
    uint8_t         op2 = state->op8;

    if (op1 < op2)
      set_C(&state->f);
    if (op1 == op2)
      set_Z(&state->f);
    set_N(&state->f);
    /* TODO: Set if no borrow from bit 4 */
    return RETURN_SUCCESS;
}
