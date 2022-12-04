/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:25:12 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 12:27:46 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_redirect_file(char *input)
{
	char	*ret_file;
	char	*root;

	ret_file = NULL;
	while (*input == ' ')
		input++;
	root = input;
	while (*input)
	{
		if (ft_strchr(" |", *input))
			break ;
		input++;
	}
	ret_file = ft_substr(root, 0, input - root);
	if (ret_file == NULL)
		return (NULL);
	return (ret_file);
}

void	store_redirect_in_out(t_shell *data, char *input)
{
	size_t	i;

	i = -1;
	while (input[++i])
	{
		if (ft_strchr("<", input[i]) && input[i + 1] == '<')
		{
			i++;
			data->cmd->fd_in = ft_strdup(".heredoc");
		}
		else if (ft_strchr("<", input[i]))
			data->cmd->fd_in = extract_redirect_file(&input[i + 1]);
		else if (ft_strchr(">", input[i]) && input[i + 1] != '>')
		{
			data->cmd->fd_out = extract_redirect_file(&input[i + 1]);
			data->cmd->outfile_mode = TRUNC;
		}
		else if (ft_strchr(">", input[i]) && input[i + 1] == '>')
		{
			data->cmd->fd_out = extract_redirect_file(&input[++i + 1]);
			data->cmd->outfile_mode = APPEND;
		}
		if (ft_strchr("\"'", input[i]))
			skip_quote(input, &i, input[i]);
	}
}
