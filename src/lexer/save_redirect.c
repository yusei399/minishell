/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:50 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/11 17:46:40 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*extra_redirect(char *in)
{
	char	*file;
	char	*root;

	file = NULL;
	while (*in == ' ')
		in++;
	root = in;
	while (*in)
	{
		if (ft_strchr(" |", *in))
			break ;
		in++;
	}
	root = ft_substr(root, 0, in - root);
	if (file == NULL)
		return (NULL);
	return (file);
}

int	check_redirect(char *input)
{
	size_t	i;

	i = 0;
	while (input[++i])
	{
		if (ft_strchr(">", input[i]) && input[i + 1] != '>'
			&& input[i + 1] != '>')
			return (false);
	}
	return (true);
}

void	pre_save_redirect(t_shell *shell, char *input)
{
	size_t	i;

	i = -1;
	while (input[++i])
	{
		if (ft_strchr("<", input[i]) && input[i + 1] == '<')
		{
			i++;
			shell->cmd->fd_in = ft_strdup(".heredoc");
		}
		else if (ft_strchr("<", input[i]))
			shell->cmd->fd_in = extract_redirect_file(&input[i + 1]);
		else if (ft_strchr(">", input[i]) && input[i + 1] != '>')
		{
			shell->cmd->fd_out = extract_redirect_file(&input[i + 1]);
			shell->cmd->outfile_mode = TRUNC;
		}
		else if (ft_strchr(">", input[i]) && input[i + 1] == '>')
		{
			shell->cmd->fd_out = extract_redirect_file(&input[++i + 1]);
			shell->cmd->outfile_mode = APPEND;
		}
		if (ft_strchr("\"'", input[i]))
			skip_quote(input, &i, input[i]);
	}
}

void	save_redirect(t_shell *shell, char *input)
{
	size_t	i;

	i = -1;
	while (input[++i])
	{
		if (ft_strchr(">", input[i]) && input[i + 1] == '>'
			&& input[i + 2] == '>')
		{
			perror("syntax error");
			break ;
		}
	}
	pre_save_redirect(shell, input);
}
