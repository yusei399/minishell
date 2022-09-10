/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:14:00 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 12:14:14 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*str;
// 	int	a;

// 	str = "1234567890";
// 	a = ft_strlen(str);
// 	printf("%d \n", a);
// }

// int main()
// {
// 	const char *str;

// 	str = NULL;

// 	int i = ft_strlen(str);
// 	printf("%d", i);

// }