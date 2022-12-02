#include "../../inc/minishell.h"

// export name=value
// name が同じやつは上書きする

int	check_export(char *arg)
{
	if (!arg)
		return (1);
	if (!ft_strstr(arg, '='))
		return (1);
	return (0);
}

char	*name_env(char	*arg)
{
	size_t	i;
	char	*name;

	i = 0;
	while (arg[i++] != '=')
		;
	name = malloc(sizeof(char ) * i);
	if (!name)
		return (NULL);
	ft_memmove(name, arg, i)
	return (name);
}

void	ft_export(t_shell *shell, char *arg)
{
	t_env	*env;
	char	*name;

	if (check_export(arg))
		return (NULL);
	name = name_env(arg);
	ft_unset(shell, name);
	free(name);
	// ここらへんの関数の使い方確認頼む
	env = new_env(arg);
	add_back_env(shell->env, env);
}
