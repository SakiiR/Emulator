#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

# define VBLANK_HANDLER     (0x40)
# define LCDSTAT_HANDLER    (0x48)
# define TIMER_HANDLER      (0x50)
# define SERIAL_HANDLER     (0x58)
# define JOYPAD_HANDLER     (0x60)

typedef struct s_game       t_game;

enum                        s_interrupt_status
{
  INTERRUPTS_ENABLED = 0,
  INTERRUPTS_DISABLED
};

typedef struct              s_interrupts
{
  enum s_interrupt_status   enabled;
}                           t_interrupts;

void                        init_interrupts(t_interrupts *interrupts);
char                        interrupts_step(t_game *game);

#endif /* !INTERRUPTS_H_ */
