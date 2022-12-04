/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:51 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:23:52 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	claen_cmd_list(t_cmd **cmd, void (*del)(void*))
{
	t_cmd	*tmp;

	if (!cmd || !del)
		return ;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		(*del)((*cmd)->commands);
		free(*cmd);
		*cmd = tmp;
	}
}
