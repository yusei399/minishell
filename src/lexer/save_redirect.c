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

void	save_redirect(t_shell *shell, char *input)
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
			shell->cmd->fd_in = extra_redirect(&input[i + 1]);
		else if (ft_strchr(">", input[i]) && input[i + 1] != '>')
		{
			shell->cmd->fd_out = extra_redirect(&input[i + 1]);
			shell->cmd->outfile_mode = TRUNC;
		}
		else if (ft_strchr(">", input[i]) && input[i + 1] == '>')
		{
			shell->cmd->fd_out = extra_redirect(&input[++i + 1]);
			shell->cmd->outfile_mode = APPEND;
		}
		if (ft_strchr("\"'", input[i]))
			ft_quote(input, &i, input[i]);
	}
}