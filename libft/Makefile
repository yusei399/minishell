CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I libft.h
NAME		=	libft.a
SRCS		=	ft_bzero.c		\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_memset.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_strlen.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_atoi.c		\
				ft_memcmp.c		\
				ft_strncmp.c	\
				ft_strrchr.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_memchr.c		\
				ft_strchr.c		\
				ft_strnstr.c	\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c   \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_striteri.c \




OBJS		=	$(SRCS:.c=.o)

BONUS = 		ft_lstnew.c	   \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstclear.c \
				ft_lstmap.c	\

BONUS_OBJS = $(BONUS:.c=.o)

ifdef WITH_BONUS
OBJS += $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) r $@ $^

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	@make WITH_BONUS=1