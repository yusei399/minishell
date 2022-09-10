/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:57 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/23 17:55:21 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			(*f)(j, s);
			s++;
			j++;
		}
	}
}

// void	ft_striteri(char *s, void (*f)(unsigned int, char*))
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		(*f)(i, &s[i]);
// 		i++;
// 	}
// }