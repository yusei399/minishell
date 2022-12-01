#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
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

# define IN 0
# define OUT 1

# define TRUNC 0
# define APPEND 1

int	g_status;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_command
{
	char	**argv;
}	t_command;


typedef struct s_cmd
{
	int					pipe[2];
	int					fd[2];
	char				*fd_in;
	char				*fd_out;
	struct s_command	*commands;
	struct s_cmd		*next;
	struct s_cmd		*prev;
	size_t				cmd_cnt;
	int					outfile_mode;
}	t_cmd;

/* ----------------------main struct-------------------------- */
typedef struct s_shell
{
	char	*input;
	// read line した文字列
	char	*arg;

	// 環境変数
	char 	**envp;

	// 分解したenvp
	t_env	*env;

	//コマンドラインの構造体
	t_cmd	*cmd;
}	t_shell;

/* ---------------------- function -------------------------- */
// lexer
int		lexer(t_shell *shell);
int 	pipe_split(t_shell *shell);
void	save_redirect(t_shell *shell, char *input);
int		quatecheck(t_shell *shell);
void	ft_quote(char *input, size_t *i, char quote);
// cmd_lst operater
void	lstadd_back(t_cmd **lst, t_cmd *new);
void	lstadd_front(t_cmd **lst, t_cmd *new);
void	lstdelone(t_cmd **lst);
int		lstsize(t_cmd *dclist);
t_cmd	*lstfirst(t_cmd *dclist);
t_cmd	*lstlast(t_cmd *lst);
t_cmd 	*lstnew(void);
char	*ft_strstr(const char *haystack, const char *needle);
char	*extract_sign(char *input);
void	write_heredoc_file(t_list *heredoc_lst);
void	loop_heredoc(char *input, t_list **heredoc_lst, t_shell *data);
void	heredoc(t_shell *data);
void	equal_devide(char** envp, t_shell *shell);
void	handle_signal(int signal);
void	split_env(t_shell *shell, char **envp);
char	*ft_getenv(t_shell *shell, char *name);
int		ft_execvp(char *file, char *argv[], t_shell *shell);

void	skip_quote(char *input, size_t *i, char quote);
size_t	count_cmds(char *input);
void	exit_session(t_shell *data, int status, char *msg);
void	exit_(char *msg, char *s);
void	exit_session(t_shell *data, int status, char *msg);
void	ft_putendl(char const *s);
void	wait_processes(t_shell *shell);
char	*store_quoted_arg(t_shell *shell, char *input, size_t *i, char quote);
char	*extract_arg(t_shell *shell, char *input, char **start, size_t *i);

//executer
void	executor(t_shell *shell);

// util
size_t	count_args(char *input);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c);
void	ft_putstr(char const *s);

//util_3
size_t	count_arg_len(char *arg, t_list **val, t_list **key);
void	copy_lst_content(char **dst, size_t *j, t_list **lst);
char	*create_expanded_arg(t_shell *data, char *arg,
			t_list **val, size_t len);

//op_env
void	extract_env_key(char *arg, t_list **env_key);
void	get_env_val(t_shell *data, t_list **val, t_list **key);
char	*extract_env_val(char *arg, t_shell *data);
char	*expand_env(char *arg, t_shell *data, bool quoted);

//signal
void	ft_putnbr(int n);
void	handle_signal(int signal);

//free
void	free_all(t_shell *shell);

//miishell
void	shell_executive(t_shell *shell);

//command
void	ft_pwd(void);
int		ft_echo(char **args);
int		ft_cd(char *dir, t_shell *shell);
void	ft_env(t_shell *shell);

//lexer
void	save_args(t_shell *shell, t_command *commands, char *input);
void	ft_format(t_shell *shell, t_command *commands, char *argv);
int		lexer(t_shell *shell);

//split_env
t_env	*last_env(t_env *env);
void	add_back_env(t_env **env, t_env *new);
t_env	*new_env(char *env);


//pipe_split
bool	arg_is_quoted(t_shell *shell);
char	**split_by_pipe(t_shell *shell, char *input, size_t cmd_cnt);


//export
#endif