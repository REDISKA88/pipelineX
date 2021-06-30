SRCS	=	child.c \
            parent.c \
            path.c \
            pipex.c \
            split.c \
            strjoin.c \
            utils.c

NAME		=	pipex

CFLAGS		=	-Wall -Werror -Wextra -o

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re