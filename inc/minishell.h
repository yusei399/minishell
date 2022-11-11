/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:54 by susui             #+#    #+#             */
/*   Updated: 2022/11/04 12:47:02 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "get_next_line.h"


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
/* ------------------------------------------------------------ */


// un used
/* --------------------------------------------------------- */
//# define BUFF_SIZE 4096
/*typedef enum e_quote
{
	SINGLE,
	DOBULE,
	NONE,
}		t_quote;*/
/*typedef enum e_boolean
{
	TRUE = 1,
	FALSE = 0,
}			t_boolean;*/
// グローバル変数
//char	**g_env;


/*
typedef struct s_io
{
	int		type;
	char	*data;
	t_io	*next;
}t_io;
 */



// function
// read line
char	*get_line(void);

// command
int		ft_cd(char *dir, t_shell *shell);
int		ft_echo(char **args);
void	pwd(void);
// void	exit(void);
char	**ft_export(char **env, char **argv);

// utils is系のfunc
int		ft_isstrcmp(const char *s1, const char *s2);
int		ft_isblank(char c);
int		ft_isname(char c);
int		ft_isredirect(char c1, char c2);
int		ft_isheredoc(char *c);
int		ft_isquote(char c);
int		ft_isblank(char c);

// utils2
int		ft_isdelimiter(char c);
int		ft_ismetachar(char c);
void	self_free(void *ptr);


t_env	*last_env(t_env *env);
void	add_back_env(t_env **env, t_env *new);
t_env	*new_env(char *env);
void	env_init(t_shell *shell, char **envp);
void	ft_env(t_shell *shell);

// lexer
int 	pipe_split(t_shell *shell);
void	save_redirect(t_shell *shell);

// cmd_lst operater
void    lstadd_back(t_cmd **lst, t_cmd *new);
void    lstadd_front(t_cmd **lst, t_cmd *new);
void    lstdelone(t_cmd **lst);
int     lstsize(t_cmd *dclist);
t_cmd   *lstfirst(t_cmd *dclist);
t_cmd   *lstlast(t_cmd *lst);
t_cmd 	*lstnew(void);



#endif