/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:50 by susui             #+#    #+#             */
/*   Updated: 2022/05/08 14:47:22 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		i = n - 1;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i--;
		}
	}
	else if (dest < src)
		ft_memcpy(dest, src, n);
	return (dest);
}
