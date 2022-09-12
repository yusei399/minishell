#include "minishell.h"

int build_judge(char *command)
{
	if (ft_strcmp(command, "echo") == 0
		|| ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "exit") == 0
		|| ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0)
		return 1;
	return 0;
}

int buildin(int argc, char **argv, char *command)
{
	int	result;

	result = 0;
	if (ft_strcmp(command, "echo") == 0)
		// ft_echo()??みたいな感じ？
}


/*
if (ft_strcmp(line, "pwd") == 0)
	pwd();
else if(!ft_strncmp(line, "echo", 3))
	ft_echo(d_line);
else if (!ft_strncmp(line, "cd", 3))
	cd(d_line);
*/