/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:39:48 by susui             #+#    #+#             */
/*   Updated: 2022/05/08 14:47:41 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*buf1, const void	*buf2, size_t	n)
{
	unsigned char	*c_buf1;
	unsigned char	*c_buf2;
	size_t			i;

	c_buf1 = (unsigned char *)buf1;
	c_buf2 = (unsigned char *)buf2;
	i = 0;
	while (i < n)
	{
		if (c_buf1[i] != c_buf2[i])
			return (c_buf1[i] - c_buf2[i]);
		i++;
	}
	return (0);
}
