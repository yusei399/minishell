/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:09:26 by susui             #+#    #+#             */
/*   Updated: 2022/11/12 09:48:09 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*lstfirst(t_cmd *dclist)
{
	t_cmd	*first;

	if (dclist == NULL)
		return (NULL);
	while (dclist)
	{
		first = dclist;
		dclist = dclist->prev;
		if (dclist == NULL)
			break ;
	}
	return (first);
}
