/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:15:18 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/21 19:39:20 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)s)[i++] = 0;
	}
}

/*バイト列 s から始まる領域の先頭 n バイトを数値ゼロで埋める関数
	1 フォーマットの引数にsize_tが使われているためindexもsize_t使用
	2 unsigned char ポインタでキャスト
	3　8bitで扱うため
*/
