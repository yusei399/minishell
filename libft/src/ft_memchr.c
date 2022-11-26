/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:57:56 by susui             #+#    #+#             */
/*   Updated: 2022/05/08 14:47:47 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t		i;
	const char	*char_buf;

	char_buf = (const char *)buf;
	i = 0;
	while (i < n)
	{
		if (char_buf[i] == (char)ch)
			return ((void *)&char_buf[i]);
		i++;
	}
	return (NULL);
}
