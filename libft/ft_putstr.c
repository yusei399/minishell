/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:09:10 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/23 18:09:13 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*str;

// 	str = "42tokyo";
// 	ft_putstr(str);
// }

/*
1,文字列を出力する
2,strをwhileで\0になるまで一文字づつ出力する
*/
