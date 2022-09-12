#include "../inc/minishell.h"

int		ft_evn(char **evn)
{
	size_t i;

	i = 0;
	while (evn[i] != NULL)
	{
		if (ft_strchr(evn[i], "=") != NULL)
			ft_putendl_fd(evn[i], 1);
		i++
	}
	return (0);
}