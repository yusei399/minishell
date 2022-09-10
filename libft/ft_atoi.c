/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:50:02 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/03 11:51:36 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_overflow(int sign)
{
	if (sign < 0)
	{
		return (LONG_MIN);
	}
	else
		return (LONG_MAX);
}

static int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	size_t			digit;
	int				sign;
	unsigned long	num;
	size_t			i;

	digit = 0;
	sign = 1;
	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i++] - '0';
		if (++digit > 19 || num > __LONG_MAX__)
			return ((int)ft_overflow(sign));
	}
	return ((int)num * sign);
}
