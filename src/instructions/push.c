#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_push_af(t_cpustate *state)
{
    push_word(state, state->af);
    return RETURN_SUCCESS;
}

int                 i_push_bc(t_cpustate *state)
{
    push_word(state, state->bc);
    return RETURN_SUCCESS;
}

int                 i_push_de(t_cpustate *state)
{
    push_word(state, state->de);
    return RETURN_SUCCESS;
}

int                 i_push_hl(t_cpustate *state)
{
    push_word(state, state->hl);
    return RETURN_SUCCESS;
}
