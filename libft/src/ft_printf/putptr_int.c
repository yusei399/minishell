/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:05:39 by susui             #+#    #+#             */
/*   Updated: 2022/06/26 16:09:15 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	lenptr(uintptr_t num)
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

void	outptr(uintptr_t num)
{
	if (num >= 16)
	{
		outptr(num / 16);
		outptr(num % 16);
	}
	else
	{
		if (num <= 9)
			putchar_int(num + '0');
		else
			putchar_int(num - 10 + 'a');
	}
}

int	put_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
	{
		outptr(ptr);
		len += lenptr(ptr);
	}
	return (len);
}
