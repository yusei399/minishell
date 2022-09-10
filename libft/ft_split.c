/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:42:33 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/01 22:22:50 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	if (*s != c)
		count++;
	s++;
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			count++;
		s++;
	}
	return (count);
}

static void	result_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
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

static int	ft_strsplit(char **result, char const *s, char c)
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
		result[j] = ft_strndup(s, i);
		if (!result[j])
		{
			result_free(result);
			return (0);
		}
		s += i;
		j++;
	}
	result[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!result)
		return (NULL);
	if (!ft_strsplit(result, s, c))
		return (NULL);
	return (result);
}
