/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:17:27 by susui             #+#    #+#             */
/*   Updated: 2022/11/27 23:23:03 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	check_long(long num, const char *str, long negative)
{
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (num > ov_div || (num >= ov_div && (*str - '0') > ov_mod))
	{
		if (negative == -1 && *str > (ov_mod + 1))
			return (LONG_MIN);
		else if (negative == 1)
			return (LONG_MAX);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	num;
	long	negative;
	long	ov_return;

	num = 0;
	negative = 1;
	ov_return = 0;
	while (((*str >= '\t' && *str <= '\r') || *str == ' ') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		ov_return = check_long(num, str, negative);
		if (ov_return != 0)
			return ((int)ov_return);
		num = 10 * num + (*str - '0');
		str++;
	}
	num *= negative;
	return (num);
}
