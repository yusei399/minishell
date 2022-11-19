/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:32:16 by susui             #+#    #+#             */
/*   Updated: 2022/11/12 10:37:09 by yuseiikeda       ###   ########.fr       */
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
