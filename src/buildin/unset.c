#include "../../inc/minishell.h"
#include "../../inc/libft.h"

static int	ft_get_index(char **envp, const char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (envp == NULL)
		ft_putstr("No env\n");
	while (envp[i] != NULL)
	{
		while (envp[i][j] && name[j] && envp[i][j] == name[j])
		{
			if (envp[i][j + 1] == "=")
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}


static char	**ft_remove_env(char **envp, int index)
{
	char **cpy;
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (envp[i] != NULL)
		i++;
	cpy = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i] != NULL)
	{
		if (i != index)
			cpy[i - count] = ft_strdup(envp[i]);
		else
			count++;
	}
}

