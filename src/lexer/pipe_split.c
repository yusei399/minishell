#include "../../inc/minishell.h"
/*
int	pipe_init(t_shell *shell, size_t pipe_count)
{
	//パイプまでの文字をコマンドに入れる
}*/

int	add_pipe_list(t_shell *shell, size_t pipe_count)
{
	size_t	i;
	t_cmd	*new;

	while(i <= pipe_count)
	{
		new = lstnew();
		if (!new)
			return (1);
		lstadd_back(&shell->cmd, new);
		// nullが帰ってきたとき(失敗した時)にfreeしなきゃ
		i++;
	}
	return (0);
}

// todo --------------------------
// []pipeで終わってるとき -> errorっぽいな
// []pipe2連のときの対処 わからん

int	pipe_count(t_shell *shell)
{
	int	pipe_count;
	int	i;

	pipe_count = 0;
	i = 0;
	while (shell->arg[i])
	{
		if (shell->arg[i] == '|')
		{
			if (shell->arg[i + 1] == '|' || !shell->arg[i + 1])
				return (-1);
			pipe_count++;
		}
		i++;
	}
	return (pipe_count);
}

int 	pipe_split(t_shell *shell)
{
	int	p_count;

	p_count = pipe_count(shell);
	// 0個だったら終わり [ok] ->
	// todo[] 一個分argを入れる
	if (p_count == -1)
		return (1);
	// pipeがある分だけリストを作ってパイプを繋げておく []
	add_pipe_list(shell, p_count);
	// lst->cmd に アーギュメントを入れていく
		// 何をいれる??
		//
//	pipe_init();
	return (0);
}
/*
int	main()
{
	t_shell shell;
	t_cmd *cmd;
	int i;

	i = 0;
	pipe_list(&shell, 1);
	cmd = shell.cmd;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	printf("%d", i);
}*/
