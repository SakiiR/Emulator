#ifndef CPU_H_
# define CPU_H_

# include <stdint.h>

# define MEMORY_SIZE (0xFFFF)

typedef struct              s_cc
{
  uint8_t                   z:1;    
  uint8_t                   s:1;    
  uint8_t                   p:1;    
  uint8_t                   cy:1;    
  uint8_t                   ac:1;    
  uint8_t                   pad:3;  
}                           t_cc;

typedef struct              s_8080state {    
  uint8_t                   a;    
  uint8_t                   b;    
  uint8_t                   c;    
  uint8_t                   d;    
  uint8_t                   e;    
  uint8_t                   h;    
  uint8_t                   l;    
  uint16_t                  sp;    
  uint16_t                  pc;    
  uint8_t                   *memory;    
  struct s_cc               cc;    
  uint8_t                   int_enable;    
}                           t_8080state;    


#endif /* !CPU_H_ */
