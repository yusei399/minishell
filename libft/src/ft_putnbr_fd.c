/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:45:05 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:14:26 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	long	nb;

	nb = i;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
