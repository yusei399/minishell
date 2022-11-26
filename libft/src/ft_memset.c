/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:39:45 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:14:08 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*c_buf;
	size_t			i;

	c_buf = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		c_buf[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
