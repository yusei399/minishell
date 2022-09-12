#include "../inc/minishell.h"

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