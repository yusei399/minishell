/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:37 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/01 23:06:46 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	k;

	src_len = ft_strlen(src);
	k = 0;
	if (dest == NULL && size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size > dest_len)
	{
		while (src[k] != '\0' && k + dest_len + 1 < size)
		{
			dest[dest_len + k] = src[k];
			k++;
		}
		dest[dest_len + k] = '\0';
		return (dest_len + src_len);
	}
	return (src_len + size);
}
