/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:54 by susui             #+#    #+#             */
/*   Updated: 2022/10/22 10:39:46 by yuseiikeda       ###   ########.fr       */
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

# define BUFF_SIZE 4096

typedef enum e_quote
{
	SINGLE,
	DOBULE,
	NONE,
}		t_quote;

// typedef enum e_boolean
// {
// 	TRUE = 1,
// 	FALSE = 0,
// }			t_boolean;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// グローバル変数
// char	**g_env;

typedef struct s_shell
{
	t_env	*env;
}t_shell;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	char			**av;
	int				ac;
	int				type;
	int				pip[2];
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

// read line
char	*get_line(void);

// command
int		ft_cd(char *dir, t_shell *shell);
int		ft_echo(char **args);
void	pwd(void);
// void	exit(void);
char	**ft_export(char **env, char **argv);

// utils
int		ft_strcmp(const char *s1, const char *s2);
int		ft_blank(char c);
int		ft_name(char c);
int		ft_redirect(char c1, char c2);
int		ft_heredoc(char *c);
int		ft_quote(char c);
int		ft_blank(char c);

// utils2
int		ft_delimiter(char c);
int		ft_metachar(char c);
int		ft_isspace(char c);
char	**alt_space_split(char	*str);
void	self_free(void *ptr);

t_env	*last_env(t_env *env);
void	add_back_env(t_env **env, t_env *new);
t_env	*new_env(char *env);
void	env_init(t_shell *shell, char **envp);
void	ft_env(t_shell *shell);

#endif