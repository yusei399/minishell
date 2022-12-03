#include "../../inc/minishell.h"

static int is_exact_match(char *input, char *end)
{
	if (ft_strlen(input) != ft_strlen(end))
		return (0);
	if (ft_strncmp(input, end, ft_strlen(end)) != 0)
		return (0);
	return (1);
}

void	clean_key(t_shell *shell, t_env *env)
{
	t_env	*tmp;

	if (!env)
	{
		tmp = env;
		shell->env = env->next;
	}
	else
	{
		tmp = env->next;
		env->next = tmp->next;
	}
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

void	ft_unset(t_shell *shell, char *key)
{
	t_env	*env;
	t_env	*pre;

	env = shell->env;
	pre = NULL;
	while (env)
	{
		if (is_exact_match(env->key, key))
		{
			clean_key(shell, pre);
			return ;
		}
		pre = env;
		env = env->next;
	}
}
