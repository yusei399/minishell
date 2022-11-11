#ifndef MINISHELL_H
# define MINISHELL_H

#include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "libft.h"
//# include "get_next_line.h"


// quote
#define NONE 0
#define SINGLE 1
#define DOUBLE 2

// bool
#define TRUE 1
#define FALSE 0



typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*command;
	int				type;
	int				pip[2];
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

/* ----------------------main struct-------------------------- */
typedef struct s_shell
{
	// read line した文字列
	char	*arg;

	// 環境変数
	char 	**envp;

	// 分解したenvp
	t_env	*env;

	//コマンドラインの構造体
	t_cmd	*cmd;
}t_shell;


/* ---------------------- function -------------------------- */
// lexer
int		lexer(t_shell *shell);
int 	pipe_split(t_shell *shell);
void	save_redirect(t_shell *shell);
int		quatecheck(t_shell *shell);



// cmd_lst operater
void	lstadd_back(t_cmd **lst, t_cmd *new);
void	lstadd_front(t_cmd **lst, t_cmd *new);
void	lstdelone(t_cmd **lst);
int		lstsize(t_cmd *dclist);
t_cmd	*lstfirst(t_cmd *dclist);
t_cmd	*lstlast(t_cmd *lst);
t_cmd 	*lstnew(void);

void	equal_devide(char** envp, t_shell *shell);


#endif