/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:43:26 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 11:53:01 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

// int main(void)
// {
// 	int i = '2';

// 	printf("%d",ft_isalpha(i));
// }

// 

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
1,引数c が英字であれば 0以外を返し、そうでなければ 0 を返す。
*/