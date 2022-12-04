#include "../../inc/minishell.h"

void	claen_cmd_list(t_cmd **cmd, void (*del)(void*))
{
	t_cmd	*tmp;

	if (!cmd || !del)
		return ;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		(*del)((*cmd)->commands);
		free(*cmd);
		*cmd = tmp;
	}
}
