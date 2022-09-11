/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:54 by susui             #+#    #+#             */
/*   Updated: 2022/09/10 15:19:40 by susui            ###   ########.fr       */
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

void	pwd(void);
void	cd(char	*path);
int 	ft_echo(char **args);

#endif