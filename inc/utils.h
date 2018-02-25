#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define DUMP_OUTFILE       ("/tmp/dump.raw")
# define PERM_OUTFILE       (S_IRWXU | S_IRWXG | S_IRWXO)
# define MODE_OUTFILE       (O_WRONLY | O_CREAT | O_TRUNC)

typedef struct s_game	    t_game;

int                         dump_memory(t_game *game);
int                         dump_vram(t_game *game);

#endif /* !UTILS_H_ */

