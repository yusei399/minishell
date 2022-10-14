/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:57 by susui             #+#    #+#             */
/*   Updated: 2022/09/24 19:45:21 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd(void)
{
	char	buf[BUFSIZ];

	if (getcwd(buf, sizeof(buf)) != NULL)
		printf("%s\n", buf);
}
