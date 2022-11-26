/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:19:03 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:16:07 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

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
