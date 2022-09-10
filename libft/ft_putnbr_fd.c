/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:22:54 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/20 22:50:15 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 		return (ft_putstr_fd("-2147483648", fd));
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		ft_putchar_fd('-', fd);
// 	}
// 	if (n < 10)
// 	{
// 		c = n + '0';
// 		ft_putchar_fd(c, fd);
// 	}
// 	else
// 	{
// 		ft_putnbr_fd((n / 10), fd);
// 		ft_putnbr_fd((n % 10), fd);
// 	}
// 	return (0);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			c = (n % 10) + '0';
			write(fd, &c, 1);
		}
	}
}

/*
1,ファイルディスクプリタを指定し標準出力する
*/