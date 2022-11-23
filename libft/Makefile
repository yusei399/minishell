NAME	= libft.a 

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_calloc.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_striteri.c ft_strndup.c \
		ft_lstiter.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstmap.c

OBJS		=	${SRCS:.c=.o}

bonus		=	ft_lstiter.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstmap.c

bonus_objs	=	${bonus:.c=.o}

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I ./include



RM			=	rm -f

ifdef WITH_BONUS
OBJS += $(bonus_objs)
endif

all: ${NAME}

$(NAME):$(OBJS)
				$(MAKE) -C ./ft_printf
				cp ./ft_printf/libftprintf.a $(NAME)
				ar -rcs $(NAME) $(OBJS)

clean:
			$(MAKE) clean -C ./ft_printf
			${RM} ${OBJS} $(bonus_objs)

fclean:clean
				$(MAKE) fclean -C ./ft_printf
				${RM} ${NAME}

re:fclean all

bonus:
	@make WITH_BONUS=1

.PHONY:
	all clean fclean re bonus