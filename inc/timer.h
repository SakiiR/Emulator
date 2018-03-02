#ifndef TIMER_H_
# define TIMER_H_

/* Launching Interrupt for some reason at some moment */ 

# define MAX_DIV        (16384)
# define TIMER_ENABLED  (1 << 2)
# define TIMER_OFFSET   (0x3) 

typedef struct s_game   t_game;

typedef struct          s_timer 
{
  unsigned long long    div;
  unsigned long long    timer;
}                       t_timer;

int                     init_timer(t_timer *timer);
int                     timer_step(t_game *game);

#endif /* !TIMER_H_ */
