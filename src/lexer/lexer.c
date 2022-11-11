/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:46 by susui             #+#    #+#             */
/*   Updated: 2022/10/22 11:47:48 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int 	lexer(t_shell *shell)
{
	//todo[] → pipe ごとのリストの作成
	pipe_split(shell);
	// クオートが正しく閉じられているかの確認
		//todo[done] 今はargでやってるから、それをpipeでわけられたリストで実行するようにする。
	if (quatecheck(shell))
		return 1;
	//todo[] →
//	save_redirect(shell);
//	formatter();
	return (0);
}

 /* ----------------------------------------------------------

int main(int argc, char **argv)
{
	t_shell shell;

	if (argc != 2)
		return 0;
	shell.arg = argv[1];
	lexer(&shell);
	shell.arg = "sdfghjksdfghjk''";
	lexer(&shell);
	return (0);
}

---------------------------------------------------------- */
