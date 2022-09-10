/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:42:33 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/14 15:47:45 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!*s)
		return (0);
	if (*s != c)
		cnt++;
	s++;
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			cnt++;
		s++;
	}
	return (cnt);
}

static void	ret_free(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_strsplit(char **ret, char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		i = 0;
		while (*(s + i) && *(s + i) != c)
			i++;
		ret[j] = ft_strndup(s, i);
		if (!ret[j])
		{
			ret_free(ret);
			return (0);
		}
		s += i;
		j++;
	}
	ret[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!s || !ret)
		return (NULL);
	if (!ft_strsplit(ret, s, c))
		return (NULL);
	return (ret);
}
