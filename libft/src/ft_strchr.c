/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:00:30 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:14:45 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
