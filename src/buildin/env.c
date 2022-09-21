
#include "../../inc/minishell.h"
#include "../../inc/libft.h"

t_env	*last_env(t_env *env)
{
	t_env	*last;
	t_env	*tmp_env;

	if (env == NULL)
		return (NULL);
	tmp_env = env;
	while (tmp_env)
	{
		last = tmp_env;
		tmp_env = tmp_env->next;
		if (tmp_env == NULL)
			break ;
	}
	return (last);
}

t_env	add_back_env(t_env *env, t_env *new)
{
	t_env	*last;

	if (last == NULL || new == NULL)
		return ;
	while (env)
	{
		*env = new;
		return ;
	}
	last = last_env(env);
	last->next = new;
}

t_env	*new_env(char *env)
{
	t_env	*new;
	size_t	key;

	new = ft_calloc(1, sizeof(t_env));
	if (new == NULL)
		return (NULL);
	key = ft_strchr(env, '=') - env;
	new->key = ft_substr(env, 0, key_len);
	new->value = ft_strdup(ft_strchr(env, '=') + 1);
	new->next = NULL;
	return (new);
}

