#include "../inc/minishell.h"
#include "../inc/libft.h"

void	add_cmd_back(t_cmd **head, char **argv, int type)
{
	t_cmd	*cmd;
	int		argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (*head == NULL)
		*head = cmd_create(argv, argc, type, 0);
	else
	{
		cmd = *head;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = cmd_create(argv, argc, type, cmd);
	}
}

t_cmd	*cmd_create(int argc, char **argv, int type, t_cmd *prev)
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
