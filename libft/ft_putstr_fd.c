/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:23:47 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/02 10:19:33 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return ;
	s_len = ft_strlen(s);
	while (INT_MAX < s_len)
	{
		write(fd, s, INT_MAX);
		s_len -= INT_MAX;
		s += INT_MAX;
	}
	write(fd, s, s_len);
}
