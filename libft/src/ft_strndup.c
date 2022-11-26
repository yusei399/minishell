/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:15:50 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/11/23 23:15:53 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (n < len)
		len = n;
	result = (char *)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}