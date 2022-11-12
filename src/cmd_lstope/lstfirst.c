/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:09:26 by susui             #+#    #+#             */
/*   Updated: 2022/09/08 11:13:36 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd 	*lstfirst(t_cmd *dclist)
{
	t_cmd 	*first;

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
