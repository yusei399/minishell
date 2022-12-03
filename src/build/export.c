#include "../../inc/minishell.h"

// export key=value
// key が同じやつは上書きする

int	check_export(char *arg)
{
	if (!arg)
		return (1);
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
	ft_memmove(key, arg, i);
	return (key);
}

void	ft_export(t_shell *shell, char *arg)
{
	t_env	*env;
	char	*key;

	if (check_export(arg))
		return ;
	key = key_env(arg);
	ft_unset(shell, key);
	free(key);
	// ここらへんの関数の使い方確認頼む
	env = new_env(arg);
	add_back_env(&shell->env, env);
}
