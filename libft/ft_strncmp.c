/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:55:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/05/01 23:07:52 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		num;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (num != 0)
			return (num);
		i++;
	}
	return (0);
}
