/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:05:54 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/01 23:06:56 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char ) * i + 1);
	if (!result)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[j])
		result[k++] = s1[j++];
	j = 0;
	while (s2[j])
		result[k++] = s2[j++];
	result[k] = '\0';
	return (result);
}
