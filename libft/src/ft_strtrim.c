/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:46:33 by susui             #+#    #+#             */
/*   Updated: 2022/11/27 23:26:44 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(char const c, char const	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && checker(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && checker(s1[j - 1], set))
		j--;
	dest = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!dest)
		return (NULL);
	c = 0;
	while (i < j)
		dest[c++] = s1[i++];
	dest[c] = '\0';
	return (dest);
}
