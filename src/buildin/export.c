#include "../../inc/minishell.h"
#include "../../inc/libft.h"

// int	len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != '=')
// 		i++;
// 	if (!str[i])
// 		return (-1);
// 	return (i);
// }

int	tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !tab[0])
		return (0);
	while (tab[i])
		i++;
	return (i);
}

// int	check_env(char *str, char **env)
// {
// 	int	size;
// 	int	i;

// 	i = 0;
// 	size = len(str);
// 	if (size == -1)
// 		return (-2);
// 	while (env[i])
// 	{
// 		while (ft_memcmp(env[i], str, size + 1) == 0)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// char	**minus(char **env, int i, char *str)
// {
// 	free(env[i]);
// 	env[i] = ft_strdup(str);
// 	return (env);
// }

// char	**add_export(char **env, char *str)
// {
// 	char	**tmp_env;
// 	int		i;

// 	i = check_env(str, env);
// 	if (i == -2)
// 		return (env);
// 	if (i == -1)
// 		return (minus(env, i, str));
// 	else
// 	{
// 		i = 0;
// 		tmp_env = malloc(sizeof(char *) * (tablen(env) + 2));
// 		while (env[i])
// 		{
// 			tmp_env[i] = env[i];
// 			i++;
// 		}
// 		tmp_env[i] = ft_strdup(str);
// 		tmp_env[i + 1] = NULL;
// 		free(env);
// 	}
// 	return (tmp_env);
// }

// char **ft_export(char **env, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (!argv[0])
// 		ft_env(env);
// 	while (argv[i])
// 	{
// 		env = add_export(env, argv[i]);
// 		i++;
// 	}
// 	return (env);
// }

int	len_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	check_in_env(char *str, char **env)
{
	int	sz;
	int	i;

	i = 0;
	sz = len_name(str);
	if (sz == -1)
		return (-2);
	while (env[i])
	{
		if (ft_memcmp(env[i], str, sz + 1) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	**minus_one(char **env, int i, char *str)
{
	free (env[i]);
	env[i] = ft_strdup(str);
	return (env);
}

char	**ad_arg_exp(char **env, char *str)
{
	char	**env2;
	int		i;

	i = check_in_env(str, env);
	if (i == -2)
		return (env);
	if (i != -1)
		return (minus_one(env, i, str));
	else
	{
		i = 0;
		env2 = malloc(sizeof(char *) * (tablen(env) + 2));
		while (env[i])
		{
			env2[i] = env[i];
			i++;
		}
		env2[i] = ft_strdup(str);
		env2[i + 1] = NULL;
		free(env);
	}
	return (env2);
}

char	**ft_export(char **env, char **av)
{
	int	i;

	i = 0;
	if (!av[0])
		ft_env(1);
	while (av[i])
	{
		env = ad_arg_exp(env, av[i]);
		i++;
	}
	return (env);
}