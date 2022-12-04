/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:43 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 12:15:59 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
