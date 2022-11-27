/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnmb_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:04:50 by susui             #+#    #+#             */
/*   Updated: 2022/11/27 23:12:10 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

int	nmb_len(long nmb)
{
	int	len;

	len = 0;
	if (nmb == 0)
		return (1);
	if (nmb < 0)
	{
		nmb *= -1;
		len ++;
	}
	while (nmb > 0)
	{
		nmb /= 10;
		len++;
	}
	return (len);
}

int	putnmb_int(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = putstr_int(num);
	free(num);
	return (len);
}
