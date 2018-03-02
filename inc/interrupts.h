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

enum                    e_interrupt_type
{
  VBLANK  = 1 << 0,  /* 0b00000001 */
  LCDSTAT = 1 << 1,  /* 0b00000010 */
  TIMER   = 1 << 2,  /* 0b00000100 */
  SERIAL  = 1 << 3,  /* 0b00001000 */
  JOYPAD  = 1 << 4   /* 0b00010000 */
};

void                        init_interrupts(t_interrupts *interrupts);
char                        interrupts_step(t_game *game);

int                         trigger_interrupt(t_game *game, const enum e_interrupt_type type);

#endif /* !INTERRUPTS_H_ */
