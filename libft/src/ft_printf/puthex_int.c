/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:07:08 by susui             #+#    #+#             */
/*   Updated: 2022/07/25 09:19:20 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_putchar_fd(char	c, int fd)
{
	write(fd, &c, 1);
}

int	lenhex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	outhex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		outhex(num / 16, format);
		outhex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	puthex_int(unsigned int num, const char format)
{
	int	len;

	len = 0;
	if (num == 0)
		len += putchar_int('0');
	else
	{
		outhex(num, format);
		len += lenhex(num);
	}
	return (len);
}
