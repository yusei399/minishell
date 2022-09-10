
#-lreadline

NAME 		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I ./include
# -fsanitize=address

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

SRCS		=	./src/minishel.c

OBJS		=	${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) $(LIB)
		$(CC) -o $(NAME) $(SRCS) $(LIB) $(CFLAGS)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) clean -C $(LIBFTDIR)
		$(RM) ${OBJS}

fclean: clean
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) ${NAME}

re : fclean all

.PHONY:
		all clean fclean re