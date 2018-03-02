#ifndef CPU_H_
# define CPU_H_

# include <stdint.h>
# include "opts.h"
# include "register.h"
# include "memory.h"
# include "card.h"

# define MEMORY_SIZE                  (0xFFFF)

struct                      s_instruction;

typedef struct              s_hregisters
{
  uint8_t		            *DIV;
  uint8_t                   *TIMA;
  uint8_t                   *TMA;
  uint8_t                   *TAC;
  uint8_t                   *IF;
  uint8_t                   *NR10;
  uint8_t                   *NR11;
  uint8_t                   *NR12;
  uint8_t                   *NR14;
  uint8_t                   *NR21;
  uint8_t                   *NR22;
  uint8_t                   *NR24;
  uint8_t                   *NR30;
  uint8_t                   *NR31;
  uint8_t                   *NR32;
  uint8_t                   *NR33;
  uint8_t                   *NR41;
  uint8_t                   *NR42;
  uint8_t                   *NR43;
  uint8_t                   *NR50;
  uint8_t                   *NR51;
  uint8_t                   *NR52;
  uint8_t                   *LCDC;
  uint8_t                   *SCY;
  uint8_t                   *SCX;
  uint8_t                   *LYC;
  uint8_t                   *LY;
  uint8_t                   *BGP;
  uint8_t                   *OBP0;
  uint8_t                   *OBP1;
  uint8_t                   *WY;
  uint8_t                   *WX;
  uint8_t                   *IE;
}                           t_hregisters;

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
    uint16_t                af; /* F is the 8 bits flags register */
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
  uint16_t                  old_pc;    
  uint16_t                  pc;    
  struct s_memory           memory;    
  uint8_t                   int_enable;    
  union {
    int8_t                  op8;
    int16_t                 op16;
  };
  struct s_hregisters       hregisters;
  struct s_instruction      *instruction;
}                           t_cpustate;    

void                        verb_state(t_cpustate *state);
int                         cpu_step(t_game *game, char verbose);
int                         init_cpu(t_cpustate *state, t_card *card);

#endif /* !CPU_H_ */
