/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:05:54 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/20 23:21:57 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_len(s1) + ft_len(s2);
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

// int	main()
// {
// 	char *s1;
// 	char *s2;
// 	char *str;
// 	s1 = "dfghjk";
// 	s2 = "ghjk";

// 	str = ft_strjoin(s1,s2);
// 	printf ("%s",str);
// 	s1 = NULL;
// 	s2 = NULL;
// 	str = ft_strjoin(s1,s2);
// 	printf ("%s",str);
// }

/*
1,s1とs2の連結からなる文字列を生成する
2,
*/