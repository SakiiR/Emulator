#include "resource.h"
#include "cpu.h"
#include "memory.h"


int                 i_add16_hl_bc(t_cpustate *state)
{
    uint16_t        op1 = state->hl;
    uint16_t        op2 = state->bc;

    state->hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_de(t_cpustate *state)
{
    uint16_t        op1 = state->hl;
    uint16_t        op2 = state->de;

    state->hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_hl(t_cpustate *state)
{
    uint16_t        op1 = state->hl;
    uint16_t        op2 = state->hl;

    state->hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_add16_hl_sp(t_cpustate *state)
{
    uint16_t        op1 = state->hl;
    uint16_t        op2 = state->sp;

    state->hl = op1 + op2;
    return RETURN_SUCCESS;
}

int                 i_inc_d_bc(t_cpustate *state)
{
    ++state->bc;
    return RETURN_SUCCESS;
}

int                 i_inc_d_de(t_cpustate *state)
{
    ++state->de;
    return RETURN_SUCCESS;
}

int                 i_inc_d_hl(t_cpustate *state)
{
    ++state->hl;
    return RETURN_SUCCESS;
}

int                 i_inc_d_sp(t_cpustate *state)
{
    ++state->sp;
    return RETURN_SUCCESS;
}

int                 i_dec_d_bc(t_cpustate *state)
{
    --state->bc;
    return RETURN_SUCCESS;
}

int                 i_dec_d_de(t_cpustate *state)
{
    --state->de;
    return RETURN_SUCCESS;
}

int                 i_dec_d_hl(t_cpustate *state)
{
    --state->hl;
    return RETURN_SUCCESS;
}

int                 i_dec_d_sp(t_cpustate *state)
{
    --state->sp;
    return RETURN_SUCCESS;
}
