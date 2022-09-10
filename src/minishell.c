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

#include "minishell.h"

<<<<<<< HEAD
int main(int argc, char **argv, char **envp)
{
=======
//./minishell で実行される
	// 入力を待つ

void	minishell(char	**envp)
{
	//
	get_next_line();
}

int	main(int argc, char **argv, char **envp)
{
>>>>>>> 9b41f87cd52a0f145c5cac835471722db44fcd65
	if (argc == 1 && argv)
		printf("%s", "最終関数呼び出し");
	else
	{
		ft_putstr_fd("minishell", 2);
		ft_putstr_fd("invalid arg",2);
		return (1);
	}
<<<<<<< HEAD
	return 0;
}
=======
	return (0);
}
>>>>>>> 9b41f87cd52a0f145c5cac835471722db44fcd65
