/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:41:30 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:13:58 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
