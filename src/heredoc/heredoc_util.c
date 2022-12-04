/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:03:15 by susui             #+#    #+#             */
/*   Updated: 2022/12/04 12:05:23 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_input(char *input, char *end)
{
	if (!input)
		return (1);
	if (is_exact_match(input, end))
		return (1);
	return (0);
}

t_list	*get_input(t_list *herelist, char *end)
{
	char	*input;
	char	*str;
	t_list	*new;

	while (1)
	{
		input = readline("> ");
		if (check_input(input, end))
			return (herelist);
		str = ft_strdup(input);
		if (!str)
			return (herelist);
		new = ft_lstnew(str);
		if (!new)
			return (herelist);
		ft_lstadd_back(&herelist, new);
	}
}

int	check_haredoc(char *arg)
{
	if (ft_strstr(arg, "<<") == NULL)
		return (1);
	return (0);
}
