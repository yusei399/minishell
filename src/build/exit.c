#include "minishell.h"

void	exit_(char *input, char *str)
{
	int	status;

	status = 0;
	if (str != NULL)
	status = 0;
	if (str != NULL)
		status = ft_atoi(str);
	while (str != NULL && *str)
	{
		if (ft_isdigit(*str) == 0)
		{
			status = 255;
			break ;
		}
		str++;
	}
	ft_putendl(input);
	g_status = status;
	exit(status);
}