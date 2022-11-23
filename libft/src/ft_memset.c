/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:39:45 by susui             #+#    #+#             */
/*   Updated: 2022/07/21 18:38:39 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
