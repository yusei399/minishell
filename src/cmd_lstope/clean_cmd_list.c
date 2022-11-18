#include "../../inc/minishell.h"

void	claen_cmd_list(t_cmd	*cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = (cmd)->next;
		free(cmd->command);
		free(cmd);
		cmd = tmp;
	}
}
