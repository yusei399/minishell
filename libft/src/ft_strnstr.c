/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:20:55 by susui             #+#    #+#             */
/*   Updated: 2022/11/23 23:15:59 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str && n == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i ++;
	}
	return (NULL);
}
