#include "resource.h"
#include "cpu.h"
#include "memory_ar.h"
#include "memory.h"


int                 i_pop_af(t_cpustate *state)
{
	state->af = pop_word(state);
    return RETURN_SUCCESS;
}

int                 i_pop_bc(t_cpustate *state)
{
	state->bc = pop_word(state);
    return RETURN_SUCCESS;
}

int                 i_pop_de(t_cpustate *state)
{
	state->de = pop_word(state);
    return RETURN_SUCCESS;
}

int                 i_pop_hl(t_cpustate *state)
{
	state->hl = pop_word(state);
    return RETURN_SUCCESS;
}
