<<<<<<< HEAD
#include "minishell.h"

void	ft_env(char **envp)
=======
#include "../inc/minishell.h"

int	ft_env(char **evn)
>>>>>>> f27ca5dd0966e21c701530c441211eb75d1c3af7
{
	size_t	i;

	i = 0;
<<<<<<< HEAD
	while (envp[i])
		printf("%s\n", envp[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	env(envp);
}
=======
	while (env[i] != NULL)
	{
		if (ft_strchr(env[i], "=") != NULL)
			ft_putendl_fd(evn[i], 1);
		i++;
	}
	return (0);
}
>>>>>>> f27ca5dd0966e21c701530c441211eb75d1c3af7
