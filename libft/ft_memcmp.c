/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:28:17 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/20 22:13:55 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d1;
	const unsigned char	*d2;
	size_t				i;

	i = 0;
	d1 = (const unsigned char *)s1;
	d2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}

/*
1,buf1,buf2を先頭からnバイト分比較する
2,比較unsight char　\0を含んでいればも比較を続けます
3,
*/