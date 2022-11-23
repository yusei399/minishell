NAME		=	libftprintf.a

SRCS			=	ft_printf.c putchr_int.c puthex_int.c putnmb_int.c putptr_int.c putstr_int.c putui_int.c

OBJS		=	${SRCS:.c=.o}

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I include

RM			=	rm -f


all: ${NAME}

$(NAME):$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
			${RM} ${OBJS}

fclean:
				${RM} ${OBJS}
				${RM} ${NAME}

re:fclean all


.PHONY:
	all clean fclean re