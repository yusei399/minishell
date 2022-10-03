#include "../inc/minishell.h"
#include "../inc/libft.h"

int	determine_input(char	*input, char **envp)
{
	if (strncmp(input, "/bin/", 5) == 0)
	{
		char *cmds[] = {input, NULL};
		execve(cmds[0], cmds, envp);
	}
	else
	{
		char *cmd = ft_strjoin("/bin/", input);
		char *cmds[] = {cmd, NULL};
		execve(cmds[0], cmds, envp);
	}
	return (0);
}


int split_envp(char **envp)
{
	char **str;
	str = ft_split(*envp, '=');
	*envp++
	printf("%", *str);
	return (0);
}

void	minishell(int argc, char **argv, char **envp)
{
	char	*line;

	while (1)
	{
		line = readline("minishell>$");
//		split_envp(envp);
		determine_input(line, envp);
		add_history(line);
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		minishell(argc, argv, envp);
	return (1);
}