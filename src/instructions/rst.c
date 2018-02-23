#include "resource.h"
#include "cpu.h"
#include "memory.h"
#include "memory_ar.h"

static void         rst(t_cpustate *state, uint8_t address)
{
  push_word(state, state->pc);
  state->pc = address;
}

int                 i_rst_00(t_cpustate *state)
{
    rst(state, 0x00);
    return RETURN_SUCCESS;
}

int                 i_rst_08(t_cpustate *state)
{
    rst(state, 0x08);
    return RETURN_SUCCESS;
}

int                 i_rst_10(t_cpustate *state)
{
    rst(state, 0x10);
    return RETURN_SUCCESS;
}

int                 i_rst_18(t_cpustate *state)
{
    rst(state, 0x18);
    return RETURN_SUCCESS;
}

int                 i_rst_20(t_cpustate *state)
{
    rst(state, 0x20);
    return RETURN_SUCCESS;
}

int                 i_rst_28(t_cpustate *state)
{
    rst(state, 0x28);
    return RETURN_SUCCESS;
}

int                 i_rst_30(t_cpustate *state)
{
    rst(state, 0x30);
    return RETURN_SUCCESS;
}

int                 i_rst_38(t_cpustate *state)
{
    rst(state, 0x38);
    return RETURN_SUCCESS;
}
