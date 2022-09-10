/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:37:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/01 23:10:42 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tmp;
	size_t	bytes;

	if (n == 0 || size == 0)
		return (ft_calloc(1, 1));
	bytes = n * size;
	if (bytes / size != n)
		return (NULL);
	tmp = malloc(n * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, n * size);
	return (tmp);
}
