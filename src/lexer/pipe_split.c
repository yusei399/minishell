#include "../../inc/minishell.h"

size_t 	pipe_count(t_shell *shell)
{
	size_t	pipe_count;
	size_t	i;

	pipe_count = 0;
	i = 0;
	while (shell->arg[i])
	{
		if (arg[i] == '|')
			pipe_count++;
		i++;
	}
	return (pipe_count);
}

void	pipe_split(t_shell *shell)
{
	size_t	pipe_count;
	// pipe があるかどうか探す
	pipe_count = pipe_count(shell);
	// 0個だったら終わり
	if (!pipe_count)
		return (1);
	// pipeがある分だけリストを作ってパイプを繋げておく

	// ここらへんはわからん
}
