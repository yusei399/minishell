CC		=	cc
CFLAGS	=	#-Wall -Wextra -Werror
LDFLAGS	=	-L$(LIBDIR) -lft -L$(shell brew --prefix readline)/lib -lreadline
NAME	=	minishell
SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	./libft
INCDIR	=	inc $(LIBDIR)/inc $(shell brew --prefix readline)/include

# find src -name \*.c | sed -e "s/$/\\\/g" | pbcopy <-- copy all src files
SRCS	=	$(shell find $(SRCDIR) -name "*.c" -type f) # fix here
OBJS	=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCS	=	$(addprefix -I,$(INCDIR))

all: libft $(NAME) $(OBJDIR)


$(OBJDIR):
	mkdir $(OBJDIR)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCS) -o $(@) -c -g $(<)
	@echo "$(<)\n     \
	$(MGN)--->$(RES) \
	$(GRN)$(@)$(RES)"

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "$(CYN)\n=====link=====$(RES)"
	@echo "$(YEL)Objects$(RES): $(OBJS)\n"
	@echo "$(YEL)Flags$(RES): $(LDFLAGS)\n"
	@echo "     $(MGN)--->$(RES) $(GRN)$(NAME)$(RES)"
	@echo "$(CYN)==============$(RES)"

libft:
	@make -C $(LIBDIR)

<<<<<<< HEAD

$(NAME): $(OBJS)  $(LIB)
		$(CC) -o $(NAME) $(SRCS) $(LIB) $(CFLAGS)
# $(GNL_OBJS)

$(LIBFT):
		$(MAKE) bonus -C $(LIBFTDIR)

libre:
	@make re -C $(LIBDIR)


clean:
	@echo "$(RED)"
	$(RM) $(OBJS)
	@$(RM)r $(OBJDIR)
	@echo "$(RES)"
	rm -rf bin

eclean:
	@echo "$(RED)"
	$(RM) $(NAME)
	@echo "$(RES)"

fclean:	clean eclean

re: fclean all

reall: libre re

.PHONY: all libft clean fclean eclean re

# SRCS		=	./src/minishell.c \
# 				./src/lexer/lexer.c \
# 				./src/lexer/pipe_split.c \
# 				./src/lexer/quote_check.c \
# 				./src/cmd_lstope/lstadd_back.c\
# 				./src/cmd_lstope/lstadd_front.c \
# 				./src/cmd_lstope/lstdelone.c \
# 				./src/cmd_lstope/lstfirst.c \
# 				./src/cmd_lstope/lstlast.c \
# 				./src/cmd_lstope/lstnew.c \
# 				./src/cmd_lstope/lstsize.c \
# 				./src/cmd_lstope/clean_cmd_list.c \
# 				./src/split_env.c \
# 				./src/lexer/save_redirect.c \
# 				./src/lexer/util.c \
# 				./src/lexer/util_1.c \
# 				./src/lexer/save_arg.c \
# 				./src/lexer/util_2.c \
# 				./src/lexer/op_env.c \
# 				./src/executor/executor.c \
# 				./src/executor/execvp.c \
# 				./src/executor/signal.c\
>>>>>>> 2a7b23e986bc941ca5fd9283b2778ded3349f70f
