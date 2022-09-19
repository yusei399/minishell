#include "../../inc/minishell.h"

int	ft_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strchr(env[i], '=') != NULL)
			ft_putendl_fd(env[i], 1);
		i++;
	}
	return (0);
}
