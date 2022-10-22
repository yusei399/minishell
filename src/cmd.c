#include "../inc/minishell.h"
#include "../inc/libft.h"

#include <stdio.h>
// void	check_bs(t_token *token)
// {
// }

// char	**make_empty(int argc)
// {
// 	int	i;
// 	char	**argv;

// 	i = 0;
// 	if (ft_calloc(argc + 1, sizeof(char *), (void **)&argv))
// 	{
// 		exit(1);
// 	}
// 	while (i < argc)
// 	{
// 		argv[i++] = 0;
// 	}
// 	return (argv);
// }

int	int_calloc(size_t n, size_t size, void **ret)
{
	*ret = (char *)malloc(size * n);
	if (!*ret)
		return (0);
	ft_memset(*ret, 0, (n * size));
	return (1);
}

t_cmd	*cmd_create(int argc, char **argv, int type, t_cmd *prev)
{
	t_cmd *cmd;

	if (argv == NULL)
		return (NULL);
	if (!int_calloc(1, sizeof(t_cmd), (void *)&cmd))
		exit(1);
	cmd->av = argv;
	cmd->ac = argc;
	cmd->type = type;
	cmd->next = 0;
	cmd->prev = prev;
	return (cmd);
}

void	add_cmd_back(t_cmd **head, char **argv, int type)
{
	t_cmd	*cmd;
	int		argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (*head == NULL)
		*head = cmd_create(argc, argv, type, 0);
	else
	{
		cmd = *head;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = cmd_create(argc, argv, type, cmd);
	}
}

int	main(int argc, char **argv)
{
	t_cmd *prev;
	t_cmd **head;

	prev = cmd_create(argc, argv, 0, prev);
	head = &prev;
	printf("%d",prev->ac);
	listPrint(prev);
}
