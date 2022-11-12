/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:05:25 by susui             #+#    #+#             */
/*   Updated: 2022/09/07 07:45:52 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	lstadd_front(t_cmd **lst, t_cmd *new)
{
	t_cmd *tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	new->next = tmp;
	*lst = new;
	return ;
}
