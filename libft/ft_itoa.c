/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:02:07 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/03 11:55:53 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_itoa_len(int n)
{
	int	itoa_len;

	itoa_len = 0;
	if (n <= 0)
		itoa_len++;
	while (n != 0)
	{
		itoa_len++;
		n = n / 10;
	}
	return (itoa_len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_itoa_len(n);
	str = malloc(sizeof(char ) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		i--;
		str[i] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
