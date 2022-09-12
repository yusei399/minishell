/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:48 by susui             #+#    #+#             */
/*   Updated: 2022/09/11 23:20:14 by yuseiikeda       ###   ########.fr       */
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
		line = get_line();
		printf("%s\n", line);
		// splitしてコマンド部分とオプション部分と出力用の部分に分ける
			//関数呼ぶ関数を呼ぶ?
		if (ft_strcmp(line, "pwd") == 0)
			pwd();
		/*
		else if(!ft_strncmp(line, "echo", 3))
			ft_echo(d_line);
		if (!ft_strncmp(line, "cd", 3))
			cd(d_line);
		*/
	}
	free(line);
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
