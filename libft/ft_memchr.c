/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:09:04 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/20 22:07:00 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        <stdio.h>
#include        <string.h>

void	*ft_memchr(const void *buf, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)buf;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)buf + i);
		i++;
	}
	return (NULL);
}

// int    main(void)
// {
//     char str1[] = "hello\0world";
//     ft_memchr(str1, 'w', 10);
//     memchr(str1, 'w', 10);
//     printf("%s\n", str1);
//     printf("%s", str1);
//     return (0);
// }

/*
1,bufの先頭からn文字分検索して、文字cがある位置を返す、\0文字があったとしても検索し続ける
2,
*/