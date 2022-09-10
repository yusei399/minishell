/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:55:44 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/22 20:55:45 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > i && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char s1[256] = "abcdef";

// 	char s2[256] = "123g";

// 	char *str;

// 	str = ft_strncpy(s1, s2, 3);
// 	// str = strncpy(s1, s2, 11);
// 	printf("%s\n", str);
// 	printf("%s\n", s1);
// 	printf("%s\n", str);

// 	return 0;
// }