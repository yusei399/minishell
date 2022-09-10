/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:55:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/22 21:07:35 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	num;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (num != 0)
			return (num);
		i++;
	}
	return (0);
}

// int    main(void)
// {
//     char            dest1[100] = "Hello";
// 	char            dest2[100] = "Hello";
//     char            src[10] = "World!";
//     unsigned int    nb;

//     nb = 3;
//     printf("ft_strncmp:%d\n", ft_strncmp(dest1, src, nb));
// 	printf("strncmp:%d\n", strncmp(dest2, src, nb));
//     return (0);
// }
