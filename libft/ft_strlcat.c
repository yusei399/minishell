/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:37 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 22:20:00 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (dest == NULL && src != NULL && size == 0)
		return (ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size > i)
	{
		while (src[k] != '\0' && k < size - i - 1)
		{
			dest[i + k] = src[k];
			k++;
		}
		dest[i + k] = '\0';
		return (i + j);
	}
	else
		return (j + size);
}

// int    main(void)
// {
//     char            dest1[100] = "Hello";
// 	char            dest2[100] = "Hello";
//     char            src[10] = "world";
//     size_t    nb;

//     nb = 8;
//     ft_strlcat(dest1, src, nb);
//     strlcat(dest2, src, nb);
//     printf("ft_strlcat:%s\n", dest1);
//     printf("strlcat:%s\n", dest2);
//     printf("strlcat:%lu\n",strlcat(dest2, src, nb));
// 	printf("strlcat:%u\n",ft_strlcat(dest1, src, nb));
//     return (0);
// }

// size_t ft_strlcat(char *dest, char *src, size_t size);
// int    main()
// {

// for (int i = 0; i < 16; i++)
// {
//     char dest[2][15] = {"Hello", "Hello"};
//     char src[] = "WorldWorldWor";
//     printf("size = %d, %d %s\n", i, ft_strlcat(dest[0], src, i), dest[0]);
//     printf("size = %d, %lu %s\n", i, strlcat(dest[1], src, i), dest[1]);
//     printf("\n");
// }
//     return 0;
// }