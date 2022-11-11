
#include "../../inc/minishell.h"

// tmp ----------------------------------------------------------------------------
int	ft_isquote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}
// --------------------------------------------------------------------------------
int	isclose(char *arg)
{
	char  	quot;
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	quot = arg[i++];
	while (arg[i])
	{
		if (ft_isquote(arg[i]) && arg[i - 1] != '\\')
			last++;
		i++;
	}
	if (last && arg[last] == quot)
		return (0);
	return (1);
}

int	quatecheck(t_shell *shell)
{
	size_t	i;
	int		quot;

	i = 0;
	quot = -1;
	while (shell->arg[i])
	{
		// quot が存在していたら 閉じられているかを確認したい
		if (quot == -1 && ft_isquote(shell->arg[i]))
		{
			quot = 1;
			if (isclose(&shell->arg[i]))
			{
				printf("no\n");
				return (1);
			}
		}
//			return (error_return("message: "));
		i++;
	}
	printf("ok\n");
	return 0;
}