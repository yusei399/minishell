/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:25:32 by susui             #+#    #+#             */
/*   Updated: 2022/12/04 12:25:46 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_processes(t_shell *shell)
{
	int		status;
	size_t	i;

	i = 0;
	status = 0;
	while (i++ < shell->cmd->cmd_cnt)
		wait(&status);
	if (status == SIGINT)
		g_status = SIGINT + 128;
	else if (status == SIGQUIT)
		g_status = SIGQUIT + 128;
	else
		g_status = WEXITSTATUS(status);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
