/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:45:40 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 11:53:07 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// int main(void)	
// {
// 	int c;
// 	c = ' ';

// 	printf("%d",ft_isascii(c));
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

/*1,asciiであるかどうかを判定する関数
*/