/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:25:19 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:25:21 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	add_back_env(t_env **env, t_env *new)
{
	t_env	*last;

	if (last == NULL || new == NULL)
		return ;
	else if (*env == NULL)
	{
		*env = new;
		return ;
	}
	last = last_env(*env);
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
	new->key = ft_substr(env, 0, key);
	new->value = ft_strdup(ft_strchr(env, '=') + 1);
	new->next = NULL;
	return (new);
}

void	split_env(t_shell *shell, char **envp)
{
	t_env	*new;
	size_t	i;

	i = 1;
	shell->env = new_env(envp[0]);
	if (shell->env == NULL)
		return ;
	while (envp[i])
	{
		new = new_env(envp[i]);
		if (new == NULL)
			return ;
		add_back_env(&shell->env, new);
		i++;
	}
}



/* ----------------------------------------------------
	t_env	*env;

	env = shell->env;
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
 ---------------------------------------------------- */
