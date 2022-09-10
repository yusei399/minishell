/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:58:55 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/14 17:41:03 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *ft_strlen(char *dest, char *src)
// {
// 	int	i;

// 	i = 0;

// 	while (src[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(size == 0))
	{
		while (src[i] != '\0' && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	src[] = "hello";
// 	char	dest[100];
// 	int		size;
// 	size = 0;
// 	size = ft_strlcpy(dest, src, size);
// 	printf("%d", size);
// }
