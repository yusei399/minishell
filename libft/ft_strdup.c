/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:36:05 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/23 17:36:22 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// int	ft_strlen(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i] != '\0')
// 	{
// 		count++;
// 		i++;
// 	}
// 	return (count);
// }

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*t;
	int		len;

	len = ft_strlen(src);
	t = malloc(sizeof(char) * (len + 1));
	if (t == NULL)
	{
		return (NULL);
	}
	ft_strcpy(t, src);
	return (t);
}

// int	main(void)
// {
// 	char *test;
// 	char *dup;

// 	test = "wertyuio";
// 	printf("test = %s\n", test);
// 	dup = ft_strdup(test);
// 	printf("dup  = %s\n", dup);
// 	printf("%p\n", dup);
// 	free(dup);
// }

/*
1,sの複製である、新しい文字列へのポインタを返す。
*/