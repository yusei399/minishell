/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:27:56 by susui             #+#    #+#             */
/*   Updated: 2022/10/22 07:36:41 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

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
