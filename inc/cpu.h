#ifndef CPU_H_
# define CPU_H_

# include <stdint.h>
# include "memory.h"
# include "card.h"

# define BIT_SET (1)
# define BIT_RESET (1)
# define ENTRY_POINT (0x0100)
# define MEMORY_SIZE (0xFFFF)
# define DEFAULT_SP  (0x0000) /* Invalid */

typedef struct              s_flags
{
  uint8_t                   z:1;  /* Zero flag */
  uint8_t                   n:1;  /* Substract flag */
  uint8_t                   h:1;  /* Half cary flag */  
  uint8_t                   c:1;  /* Carry flag */
  uint8_t                   pad:4; /* Padding 4 to lead to 8 bits */ 
}                           t_flags;

typedef struct              s_cpustate {    
  union {
    struct {
#ifdef M_LITTLE_ENDIAN 
      uint8_t               a;    
      uint8_t               f;    
#else
      uint8_t               f;    
      uint8_t               a;    
#endif
    };
    uint16_t                af;
  };
  union {
    struct {
#ifdef M_LITTLE_ENDIAN 
      uint8_t               b;    
      uint8_t               c;    
#else
      uint8_t               c;    
      uint8_t               b;    
#endif
    };
    uint16_t                bc;
  };
  union {
    struct {
#ifdef M_LITTLE_ENDIAN 
      uint8_t               d;    
      uint8_t               e;    
#else
      uint8_t               e;    
      uint8_t               d;    
#endif
    };
    uint16_t                de;
  };
  union {
    struct {
#ifdef M_LITTLE_ENDIAN 
      uint8_t               h;    
      uint8_t               l;    
#else
      uint8_t               l;    
      uint8_t               h;    
#endif
    };
    uint16_t                hl;
  };
  uint16_t                  sp;    
  uint16_t                  pc;    
  t_memory                  memory;    
  struct s_flags            flags;    
  uint8_t                   int_enable;    
  uint8_t                   op8;
  uint16_t                  op16;
}                           t_cpustate;    

int                         emulate(t_card *card);

#endif /* !CPU_H_ */
