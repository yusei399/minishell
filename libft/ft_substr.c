/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:59:55 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/22 21:09:01 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_slen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*tmp;
// 	size_t	slen;
// 	size_t	last;

// 	last = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	slen = ft_slen(s);
// 	if (start < slen)
// 		last = slen - start;
// 	if (last > len)
// 		last = len;
// 	tmp = (char *)malloc(sizeof(char ) * (last + 1));
// 	if (!tmp)
// 		return (0);
// 	ft_strlcpy(tmp, s + start, last + 1);
// 	return (tmp);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start <= len)
	{
		len = ft_strlen(s) - start;
	}
	result = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = *(s + start + i);
		i++;
	}
	result[i] = '\0';
	return (result);
}
