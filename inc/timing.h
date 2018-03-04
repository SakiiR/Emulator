#ifndef TIMING_H_
# define TIMING_H_

# define MAX_CYCLE_TO_REFRESH       (500)

typedef struct s_game               t_game;

int                                 timing_step(t_game *game);

#endif /* !TIMING_H_ */
