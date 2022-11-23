/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnmb_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:04:50 by susui             #+#    #+#             */
/*   Updated: 2022/07/25 09:19:35 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

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

static char	*ft_itoa(int n)
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
