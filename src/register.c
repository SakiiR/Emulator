#include "register.h"

void                                    zero_flag_check(uint8_t *f, uint8_t result)
{
  if (result == 0)
    set_Z(f);
  else 
    reset_Z(f);
}

void                                    substract_flag_check(uint8_t *f, uint8_t result)
{
  (void)f;
  (void)result;
}

void                                    half_carry_check(uint8_t *f, uint8_t a, uint8_t b)
{
  if (IS_HALF_CARRY(a, b))
    set_H(f);
  else
    reset_H(f);
}

void                                    carry_check(uint8_t *f, uint8_t a, uint8_t b, uint8_t result)
{
  if (IS_CARRY(a, b, result))
    set_C(f);
  else
    reset_C(f);
}

