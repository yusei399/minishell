/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:49:04 by susui             #+#    #+#             */
/*   Updated: 2022/12/05 08:29:18 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

char	*get_end(char *input)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i] && count < 2)
	{
		if (input[i] == '<')
			count ++;
		i++;
	}
	while (ft_isspace(input[i]))
		i++;
	return (ft_strdup(&input[i]));
}

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

void	loop_heredoc(char *input, t_list **herelist, t_shell *data)
{
	char	*end;
	char	*heredoc_input;
	char	*ret;
	t_list	*node;

	end = get_end(input);
	while (1)
	{
		heredoc_input = readline("> ");
		if (heredoc_input == NULL)
		{
			free(end);
			return ;
		}
		if (ft_strcmp(end, heredoc_input) == 0)
		{
			free(heredoc_input);
			free(end);
			return ;
		}
		ret = expand_env(heredoc_input, data, true);
		node = ft_lstnew(ret);
		free(heredoc_input);
		ft_lstadd_back(herelist, node);
	}
}

void	heredoc(t_shell *shell)
{
	t_list	*herelist;

	herelist = NULL;
	if (!(ft_strstr(shell->input, "<<")))
		return ;
	loop_heredoc(shell->input, &herelist, shell);
	output_list(herelist);
	ft_lstclear(&herelist, free);
}
