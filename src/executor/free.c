

#include "../../inc/minishell.h"

void	free_index(char **dp);

void	free_all(t_shell *shell)
{
	size_t	i;

	i = 0;
	free(shell->input);
	if (shell->cmd->fd_in)
		free(shell->cmd->fd_in);
	if (shell->cmd->fd_out)
		free(shell->cmd->fd_out);
	while (i < shell->cmd->cmd_cnt)
	{
	}
}

void	free_index(char **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
		free(dp[i++]);
	free(dp);
}
