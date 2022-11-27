/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putui_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:06:25 by susui             #+#    #+#             */
/*   Updated: 2022/11/27 23:27:19 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*uitoa(unsigned int num)
{
	int		len;
	char	*c_num;

	len = numlen(num);
	c_num = (char *)malloc(sizeof(char) * len + 1);
	if (!c_num)
		return (NULL);
	c_num[len] = '\0';
	while (num > 0)
	{
		c_num[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (c_num);
}

int	putui_int(unsigned int num)
{
	int		len;
	char	*c_num;

	len = 0;
	if (num == 0)
		len = putchar_int('0');
	else
	{
		c_num = uitoa(num);
		len += putstr_int(c_num);
		free(c_num);
	}
	return (len);
}
