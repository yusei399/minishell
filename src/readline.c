#include "../inc/minishell.h"

char **g_env;

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

int	main(int argc, char **argv, char **env)
{
	char	*command;

	while (1)
	{
		command = get_line();
		printf("%s\n", command);
		if (ft_strcmp(command, "export") == 0)
			ft_export(env, argv);
		if (ft_strcmp(command, "env") == 0)
			ft_env(1);
	}
	free(command);
	return (0);
}