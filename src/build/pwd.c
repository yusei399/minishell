/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:39 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:23:40 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	ft_putendl(cwd);
}
