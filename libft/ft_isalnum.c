/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:48:03 by susui             #+#    #+#             */
/*   Updated: 2022/05/18 09:34:42 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalnum(int	c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
