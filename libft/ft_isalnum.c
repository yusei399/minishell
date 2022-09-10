/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:37:48 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 11:52:55 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isalnum(int c)
{
	return (('0' <= c && c <= '9')
		|| ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

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
1cの文字が'0'～'9'/'A'～'Z'/'a'～'z'の場合は0以外の値、それ以外の場合は0を返す関数
2
*/
