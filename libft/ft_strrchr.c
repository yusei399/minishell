/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:19:03 by susui             #+#    #+#             */
/*   Updated: 2022/05/01 11:55:35 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	c = (char)c;
	if (c == '\0')
		return ((char *)s + i);
	while (i-- > 0)
	{
		if (*(s + i) == c)
			return ((char *)s + i);
	}
	return (NULL);
}
