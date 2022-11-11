/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:42:48 by susui             #+#    #+#             */
/*   Updated: 2022/11/04 12:53:22 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	minishell(char **argv, char	**envp)
{
	char *line;
	char **d_line;

	line = NULL;
	// 入力待ち
	while (1)
	{
		line = get_line();
		printf("%s\n", line);
		
		// splitしてコマンド部分とオプション部分と出力用の部分に分ける
			// 0番目がコマンド 2番めがオプション 3番めが引数

		// d_line = alt_space_split(line);
			//関数呼ぶ関数を呼ぶ?

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
