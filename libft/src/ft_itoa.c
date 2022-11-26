/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:17:10 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:12:35 by yuseiikeda       ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	long	nmb;
	int		len;
	char	*nmb_str;

	nmb = n;
	len = nmb_len(nmb);
	nmb_str = (char *)malloc(sizeof(char) * len + 1);
	if (!nmb_str)
		return (NULL);
	nmb_str[len] = '\0';
	len--;
	if (nmb == 0)
		nmb_str[0] = '0';
	if (nmb < 0)
	{
		nmb_str[0] = '-';
		nmb *= -1;
	}
	while (nmb > 0)
	{
		nmb_str[len] = '0' + (nmb % 10);
		nmb /= 10;
		len--;
	}
	return (nmb_str);
}
