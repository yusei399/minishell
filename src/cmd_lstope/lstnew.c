/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:41:23 by susui             #+#    #+#             */
/*   Updated: 2022/11/19 17:32:51 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*lstnew(void)
{
	t_cmd	*lst;

	lst = (t_cmd *)malloc(sizeof(t_cmd));
	if (lst == NULL)
		return (NULL);
	*lst = (t_cmd ){0, 0, 0, 0, 0, 0, NULL};
	return (lst);
}

/*
int main(void)
{
	t_cmd *lst;

	lst = NULL;
	lst = lstnew();
	lst->type = 100;
	printf("lst: %d", lst->type);
	free(lst);
}
*/

