#include "../inc/minishell.h"

char	*get_line(void)
{
	char	*read_line;

	read_line = NULL;
	read_line = readline("minishell>> ");
	if (read_line == NULL)
		return (NULL);
	if (read_line && *read_line)
		add_history(read_line);
	return (read_line);
}

// int	main(void)
// {
// 	char	*command;

// 	while (1)
// 	{
// 		command = rl_gets();
// 		printf("%s\n", command);
// 		if (ft_strcmp(command, "clear_history") == 0)
// 			rl_clear_history();
// 	}
// 	free(command);
// 	return (0);
// }