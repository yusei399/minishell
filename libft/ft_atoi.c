/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:50:02 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/23 17:08:29 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

// long	ft_overflow(int j)
// {
// 	if (j < 0)
// 	{
// 		return (- (LONG_MAX) - 1);
// 	}
// 	return (LONG_MAX);
// }

// int	ft_long(const char *str, int j)
// {
// 	size_t			digit;
// 	unsigned long	num;
// 	size_t			i;

// 	digit = 0;
// 	i = 0;
// 	num = 0;
// 	while (ft_isdigit(str[i]))
// 	{
// 		num = (num * 10) + (str[i++] - '0');
// 		if (++digit > 19 || num > __LONG_MAX__)
// 		{
// 			return ((int)ft_overflow(j));
// 		}	
// 	}
// 	return ((int)num * j);
// }

// int	ft_atoi(const char *str)
// {
// 	size_t	i;
// 	int		nbr;
// 	int		j;

// 	i = 0;
// 	nbr = 0;
// 	j = 1;
// 	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
// 			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
// 		i++;
// 	if (str[i] != '\0' && str[i] == '-')
// 	{
// 		j = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	nbr = ft_long(&str[i], j);
// 	if (j == 1)
// 		return ((int) - nbr);
// 	return ((int)nbr);
// }

long	ft_overflow(int sign)
{
	if (sign < 0)
	{
		return (-(__LONG_MAX__) - 1);
	}
	else
		return (__LONG_MAX__);
}

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	size_t			digit;
	int				sign;
	unsigned long	num;
	size_t			i;

	digit = 0;
	sign = 1;
	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (isdigit(str[i]))
	{
		num = num * 10 + str[i++] - '0';
		if (++digit > 19 || num > __LONG_MAX__)
			return ((int)ft_overflow(sign));
	}
	return ((int)num * sign);
}

/*  atoiは文字ストリングを整数値に直す関数
	1 string '\0'文字になるまでwhile回してスペースを取り除く
	2 strが\0になるまでwhileを回し-が見つかればj=1にする
	3+が見つかればi++を行う
	4jが１であれば-で出力する
*/

// int main(void) {
//     char str[] = "-----1267890asdfgh345";
//     int num;
//     // 文字列型からint型への変換
//     num = ft_atoi(str);
//     printf("int型変数numの値は: %d\n", num);
//     return 0;
// }
