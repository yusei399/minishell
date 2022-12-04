/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:26 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:23:27 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	exit_(char *input, char *str)
{
	int	status;

	status = 0;
	if (str != NULL)
	status = 0;
	if (str != NULL)
		status = ft_atoi(str);
	while (str != NULL && *str)
	{
		if (ft_isdigit(*str) == 0)
		{
			status = 255;
			break ;
		}
		str++;
	}
	ft_putendl(input);
	g_status = status;
	exit(status);
}