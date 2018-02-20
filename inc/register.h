#ifndef REGISTER_H_
# define REGISTER_H_

# include <stdint.h>
# include "cpu.h"

# define IS_NEG(a)	                  (a >> ((sizeof(a) * 8) - 1))
# define IS_POS(a)	                  ((~a) >> ((sizeof(a) * 8) - 1))
# define IS_HALF_CARRY(a, b)          (((((a & 0xf) + (b & 0xf)) & 0x10) == 0x10))
# define IS_CARRY(a, b, res)          (((IS_NEG(a) & IS_NEG(b)) | (IS_NEG(a) & IS_POS(res)) | (IS_NEG(b) & IS_POS(res)))) /* TODO: Carry Flag check  */

enum                                    flags_offset
{
  CARRY_FLAG = 4,
  HALF_CARRY_FLAG,
  SUBSTRACT_FLAG,
  ZERO_FLAG,
};

enum                                    flag_status
{
  BIT_SET = 1,
  BIT_RESET = 0,
};


/* Generator - extract good (offset) bit from uint8_t f */
/* ty https://github.com/aessiane */

# define f_get(flag, offset)				                                		\
static inline enum flag_status               get_##flag(uint8_t *f)  		        \
{			                            							                \
  return ((*f & (1 << offset)) >> offset);					                        \
}


# define f_set(flag, offset)						                                \
  static inline void		                set_##flag(uint8_t *f)                  \
{										                                            \
  *f |= (1 << offset);							                                    \
}

# define f_reset(flag, offset)					                                    \
  static inline void		                reset_##flag(uint8_t *f)                \
{										                                            \
  *f &= ~(1 << offset);							                                    \
}

f_get(C, CARRY_FLAG)
f_get(H, HALF_CARRY_FLAG)
f_get(N, SUBSTRACT_FLAG)
f_get(Z, ZERO_FLAG)

f_set(C, CARRY_FLAG)
f_set(H, HALF_CARRY_FLAG)
f_set(N, SUBSTRACT_FLAG)
f_set(Z, ZERO_FLAG)

f_reset(C, CARRY_FLAG)
f_reset(H, HALF_CARRY_FLAG)
f_reset(N, SUBSTRACT_FLAG)
f_reset(Z, ZERO_FLAG)

void                                        zero_flag_check(uint8_t *f, uint8_t result);
void                                        substract_flag_check(uint8_t *f, uint8_t result);
void                                        half_carry_check(uint8_t *f, uint8_t a, uint8_t b);
void                                        carry_check(uint8_t *f, uint8_t a, uint8_t b, uint8_t result);

#endif /* !REGISTER_H_ */
