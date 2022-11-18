/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:05:25 by susui             #+#    #+#             */
/*   Updated: 2022/11/12 09:47:54 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	lstadd_front(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	new->next = tmp;
	*lst = new;
	return ;
}
