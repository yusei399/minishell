#include "../../inc/minishell.h"

int	check_export(t_shell *shell,char *arg)
{
	if (!arg)
	{
		ft_env(shell);
		return (1);
	}
	if (!ft_strstr(arg, "="))
		return (1);
	return (0);
}

char	*key_env(char	*arg)
{
	size_t	i;
	char	*key;

	i = 0;
	while (arg[i++] != '=')
		;
	key = malloc(sizeof(char ) * i);
	if (!key)
		return (NULL);
	ft_strlcpy(key, arg, i);
	return (key);
}

int	ft_export(t_shell *shell, char *arg)
{
	t_env	*env;
	char	*key;

	if (check_export(shell, arg))
		return (0);
	key = key_env(arg);
	ft_unset(shell, key);
	free(key);
	// todo
	env = new_env(arg);
	add_back_env(&shell->env, env);
	return (0);
}
