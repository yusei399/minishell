/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:20 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:23:21 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	env_init(t_shell *shell, char **envp)
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

void	ft_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
}
