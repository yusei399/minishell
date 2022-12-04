/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 12:16:15 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	output_list(t_list *herelist)
{
	int		fd;
	char	*line;
	t_list	*list;

	list = herelist;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC \
		| S_IRUSR | S_IWUSR, 0644);
	if (fd < 0)
		return ;
	while (list)
	{
		line = list->content;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		list = list->next;
	}
}

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

char	*get_end(char *arg)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (arg[i] && count < 2)
	{
		if (arg[i] == '<')
			count ++;
		i++;
	}
	while (ft_isspace(arg[i]))
		i++;
	return (ft_strdup(&arg[i]));
}

int	is_exact_match(char *input, char *end)
{
	if (ft_strlen(input) != ft_strlen(end))
		return (0);
	if (ft_strncmp(input, end, ft_strlen(end)) != 0)
		return (0);
	return (1);
}

void	treat_heredoc(t_shell *shell)
{
	char	*end;
	t_list	*herelist;

	herelist = malloc(sizeof(t_list));
	ft_bzero(&herelist, sizeof(t_list));
	if (check_haredoc(shell->input))
		return ;
	end = get_end(shell->input);
	if (!end)
		return ;
	herelist = get_input(herelist, end);
	free(end);
	output_list(herelist);
	ft_lstclear(&herelist, free);
}
