/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:22:30 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:16:17 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

char	*s_malloc(size_t len, size_t s_len)
{
	char	*dest;

	if (len < s_len)
		dest = (char *)malloc(sizeof(char) * len + 1);
	else
		dest = (char *)malloc(sizeof(char) * s_len + 1);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int	start, size_t	len)
{
	char			*dest;
	size_t			i;
	unsigned int	s_len;

	if (s == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if (len == 0 || (start >= s_len))
	{
		dest = (char *)malloc(1);
		if (!dest)
			return (NULL);
		*dest = 0;
		return (dest);
	}
	dest = s_malloc(len, s_len);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
