/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:41:23 by susui             #+#    #+#             */
/*   Updated: 2022/09/07 08:27:59 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd 	*lstnew(void)
{
	t_cmd 	*lst;

	lst = (t_cmd *)malloc(sizeof(t_cmd));
	if (lst == NULL)
		return (NULL);
	*lst = (t_cmd ){0, 0, 0, 0, 0, 0, 0};
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

