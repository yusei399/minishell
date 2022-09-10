/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:04:41 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/03 11:52:53 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	setcheck(char s, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		head;
	size_t		tail;
	size_t		i;
	char		*str;

	head = 0;
	tail = 0;
	i = 0;
	if (set == NULL || s1 == NULL)
		return ((char *)s1);
	tail = ft_strlen(s1);
	while (s1[head] && setcheck(s1[head], set))
		head++;
	while (tail > head && setcheck(s1[tail - 1], set))
		tail--;
	str = (char *)malloc(sizeof(char ) * (tail - head + 1));
	if (!str)
		return (NULL);
	while (head < tail)
		str[i++] = s1[head++];
	str[i] = '\0';
	return (str);
}
