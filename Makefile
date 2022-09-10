
#-lreadline

NAME 		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I ./include
# -fsanitize=address

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

GNL_SRC         =       ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL_PATH        =       ./get_next_line/
GNL_OBJS        =       $(GNL_SRC:.c=.o)

SRCS		=	./src/minishell.c ./src/cd.c ./src/pwd.c

OBJS		=	${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIB)
		$(CC) -o $(NAME) $(SRCS) $(GNL_OBJS) $(LIB) $(CFLAGS)
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