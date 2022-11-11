/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:32:16 by susui             #+#    #+#             */
/*   Updated: 2022/09/07 07:45:20 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	lstsize(t_cmd *dclist)
{
	int	len;

	len = 0;
	while (dclist)
	{
		dclist = dclist->next;
		len++;
	}
	return (len);
}
