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

	i = 0;
	while (arg[i] != '=')
		i++;
	return (ft_strndup(arg, i));
}

int	ft_export(t_shell *shell, char *arg)
{
	t_env	*env;
	char	*key;

	if (check_export(shell, arg))
		return (0);
	env = malloc(sizeof(t_env));
	if (!env)
		return (1);
	env->key = ft_substr(arg, 0, (ft_strchr(arg, '=') - arg));
	ft_unset(shell, env->key);
	env->value = ft_strdup(ft_strchr(arg, '=') + 1);
	env->next = NULL;
	add_back_env(&shell->env, env);
	return (0);
}


