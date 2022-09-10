/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:37:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/23 17:26:57 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tmp;
	size_t	bytes;

	if (n == 0 || size == 0)
		return (ft_calloc(1, 1));
	tmp = malloc(n * size);
	if (!tmp)
		return (NULL);
	bytes = n * size;
	if (bytes / size != n)
		return (NULL);
	ft_bzero(tmp, n * size);
	return (tmp);
}

/*
1sizeのブロックをn個割り当てる関数
2tmpでn*size分のメモリを確保する
3確保できなかったらNULLで返す
40で埋める
*/
