#include "../inc/minishell.h"
#include "../inc/libft.h"

size_t	find_first_equal(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '=')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, n);
	return (dest);
}
//char **equal_devide(char** envp)
void	equal_devide(char** envp, t_shell *shell)
{
	size_t	first_direction;
	size_t	i;

	i = 0;
	while (envp[i])
	{
		first_direction = find_first_equal(envp[i]);
		ft_strndup(envp[i], first_direction);
		ft_strndup(&envp[i][first_direction], ft_strlen(envp[i]) - first_direction + 1);
		i++;
	}
/* ------------------------------------------------------------------------------------------------------------
		printf("\n\n-----------------------------------------------------------------\n");
		first_direction = find_first_equal(envp[i]);
		printf("full env: %s\n", envp[i]);
		printf("direction: %zu\n", first_direction);
		printf("name of env: %s\n\n", ft_strndup(envp[i], first_direction));
		printf("value of env: %s\n", ft_strndup(&envp[i][first_direction], ft_strlen(envp[i]) - first_direction + 1));


------------------------------------------------------------------------------------------------------------ */
}

/*
int split_envp(char **envp)
{
	if (equal_devide(envp, t_main))
		return (1);
	return (0);
}
*/



int main(int argc, char **argv, char **envp)
{
	equal_devide(envp);
}