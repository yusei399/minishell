#include "minishell.h"

void	ft_env(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	env(envp);
}