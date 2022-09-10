/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:44:35 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 11:53:14 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// int main(void)
// {
// 	int c;

// 	c = '5';
// 	printf("%d",isdigit(c));
// }

// int	main()
// {
// 	int	test1;
// 	test1 = '0';

// 	int test2;
// 	test2 = 'a';

// 	int test3;
// 	test3 = 'A';
// 	while (test1 <= '9')
// 	{
// 		printf("%d",ft_isdigit(test1));
// 		test1++;
// 	}
// 	printf("\n");

// 	while(test2 <= 'z')
// 	{
// 		printf("%d", ft_isdigit(test2));
// 		test2++;
// 	}
// 	printf("\n");

// 	while (test3 <= 'Z')
// 	{
// 		printf("%d", ft_isdigit(test3));
// 		test3++;
// 	}
// 	printf("\n");
// 	return (0);
// }

/*
1,引数が数字であるかどうかを判定する
*/