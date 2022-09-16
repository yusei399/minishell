/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:54 by susui             #+#    #+#             */
/*   Updated: 2022/09/16 04:16:32 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef enum e_quote
{
	SINGLE,
	DOBULE,
	NONE,
}		t_quote;

typedef enum e_boolean
{
	TRUE = 1,
	FALSE = 0,
}			t_boolean;
// read line
char	*get_line(void);

// command
void	ft_cd(char	*path);
int		ft_echo(char **args);
<<<<<<< HEAD
void	ft_cd(char	*path);
void	ft_pwd(void);
void	ft_exit(void);
void	ft_export(char *string);
=======
void	cd(char	*path);
void	pwd(void);
// void	exit(void);
void	export(char *string);
>>>>>>> f27ca5dd0966e21c701530c441211eb75d1c3af7

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

#endif