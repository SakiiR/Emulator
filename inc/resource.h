#ifndef RESOURCE_H_
# define RESOURCE_H_

# include "card.h"

# define RETURN_FAILURE (1)
# define RETURN_SUCCESS (0)
# define SYSCALL_ERROR  (-1)
# define READ_SIZE      (4096)

# define MALLOC_FAILURE ("[-] malloc() failed to allocate memory")
# define NO_GBCARD ("[-] Probably not a GB card (< HEADER_SIZE)")

#endif /* !RESOURCE_H_ */
