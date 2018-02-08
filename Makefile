CC = gcc

RM = rm -rf

LDFLAGS +=  

CFLAGS += -Iinc -W -Werror -Wall -g3

SRCS = $(shell find src/ -type f -name "*.c")

OBJS = $(SRCS:.c=.o)

MKDIR = mkdir -p

NAME = emulator

OUTDIR = bin

all: $(NAME)

$(NAME): $(OBJS)
	$(MKDIR) $(OUTDIR)
	$(CC) -o $(OUTDIR)/$(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OUTDIR)

re: fclean all

.PHONY: all re clean fclean
