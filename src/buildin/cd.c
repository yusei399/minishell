

#include	"../../inc/minishell.h"
#include	"../../inc/libft.h"

void	error_msg(char **argv)
{
	ft_putstr_fd("cd :", 2);
	if (argv[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(argv[1], 2);
}

char	*get_env_path(t_env *env, const char *var, size_t len)
{
	char	*old_path;
	int		i;
	int		j;
	int		malloc_len;

	while (env && env->next != NULL)
	{
		if (ft_strncmp(env->value, var, len) == 0)
		{
			malloc_len = ft_strlen(env->value) - len;
			if (!(old_path = malloc(sizeof(char) * malloc_len + 1)))
				return (NULL);
			
		}
	}
}

void	ft_cd(char	*path)
{
	chdir(path);
}

