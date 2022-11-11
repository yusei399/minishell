NAME 		=	minishell
CC			=	cc
CFLAGS		=	-lreadline -I ./include
# -fsanitize=address
#	-Wall -Wextra -Werror

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

#GNL_SRC         =       ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
#GNL_PATH        =       ./get_next_line/
#GNL_OBJS        =       $(GNL_SRC:.c=.o)

SRCS		=	./src/minishell.c \
				./src/lexer/lexer.c \
				./src/lexer/pipe_split.c \
				./src/lexer/quote_check.c \
				./src/lstope/lstadd_back.c\
				./src/lstope/lstadd_front.c \
				./src/lstope/lstdelone.c \
				./src/lstope/lstfirst.c \
				./src/lstope/lstlast.c \
				./src/lstope/lstnew.c \
				./src/lstope/lstsize.c \
				./src/split_env.c

OBJS		=	${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS)  $(LIB)
		$(CC) -o $(NAME) $(SRCS) $(LIB) $(CFLAGS)
# $(GNL_OBJS)

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