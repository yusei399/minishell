/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:11:30 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/22 21:06:46 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// char	*ft_strrchr(const char *s, int c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = NULL;
// 	while (s[i])
// 		i++;
// 	if ((char)c == '\0')
// 	{
// 		str = (char *)(s + i);
// 		return (str);
// 	}
// 	while (i--)
// 	{
// 		if (s[i] == (char)c)
// 			str = (char *)(s + i);
// 	}
// 	return (str);
// }

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
