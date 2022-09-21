#include "../inc/minishell.h"

char	**g_env;

void	init_environ(char **envir)
{
	int	i;

	i = 0;
	while (envir[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 3));
	g_env[0] = ft_strdup("?=0");
	g_env[1] = ft_strdup("-flag=0");
	i = 0;
	while (envir[i])
	{
		g_env[i + 2] = ft_strdup(envir[i]);
		i++;
	}
	g_env[i + 2] = NULL;
}

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
	char	*cenv;

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