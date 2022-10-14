/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:27:56 by susui             #+#    #+#             */
/*   Updated: 2022/10/14 15:48:17 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_calloc(size_t n, size_t size, void **p)
{
	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	if (size == 0 || n == 0)
	{
		p = malloc(1);
		size = 1;
		n = 1;
	}
	else
		p = (void *)malloc(n * size);
	if (!p)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}
