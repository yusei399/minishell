/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:48 by susui             #+#    #+#             */
/*   Updated: 2022/09/09 15:42:49 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	minishell(char **argv, char	**envp)
{
	char *line;

	line = NULL;
	// 入力待ち
	while (1)
	{
		line = readline("minishell>> ");
		if (line == NULL || strlen(line) == 0)
		{
			free(line);
			break;
		}

		// splitしてコマンド部分とオプション部分と出力用の部分に分ける

		if (!ft_strncmp(line, "pwd", 3))
			pwd();
		else if(!ft_strncmp(line, "echo", 3))
			ft_echo(d_line);
		if (!ft_strncmp(line, "cd", 3))
			 cd(d_line);
		add_history(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1 && argv)
		minishell(argv, envp);
	else
	{
		ft_putstr_fd("minishell", 2);
		ft_putstr_fd("invalid arg",2);
		return (1);
	}
	return (0);
}
