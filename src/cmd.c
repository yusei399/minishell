#include "../inc/minishell.h"
#include "../inc/libft.h"

t_cmd *cmd_create(int argc, char **argv, int type, t_cmd *prev)
{
	t_cmd *cmd;

	if (argv == NULL)
		return (NULL);
	if (!ft_calloc(1, sizeof(t_cmd), (void *)&cmd))
		exit(1);
	cmd->av = argv;
	cmd->ac = argc;
	cmd->type = type;
	cmd->next = 0;
	cmd->prev = prev;
	return (cmd);
}