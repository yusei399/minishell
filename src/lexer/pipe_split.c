#include "minishell.h"

void	skip_quote(char *input, size_t *i, char quote)
{
	size_t	j;

	j = *i + 1;
	while (input[j])
	{
		if (input[j] == quote)
			break ;
		j++;
	}
	*i = j;
}

bool	arg_is_quoted(t_shell *shell)
{
	size_t	i;
	char	*input;
	char	quote;

	i = 0;
	input = shell->input;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			quote = input[i];
			skip_quote(input, &i, quote);
			if (input[i] != quote)
				return (false);
			break ;
		}
		i++;
	}
	return (true);
}

size_t	count_cmds(char *input)
{
	size_t	cmd_cnt;
	size_t	i;

	i = 0;
	cmd_cnt = 1;
	while (input[i])
	{
		if (input[i] == '\"')
			skip_quote(input, &i, '\"');
		else if (input[i] == '\'')
			skip_quote(input, &i, '\'');
		else if (input[i] == '|')
		{
			cmd_cnt++;
			i++;
		}
		i++;
	}
	return (cmd_cnt);
}

/*
	Split per pipe and extract command line
	 (ignore pipes in double and single quarts)
*/
char	**split_by_pipe(t_shell *shell, char *input, size_t cmd_cnt)
{
	size_t	i;
	size_t	j;
	char	**ret;
	char	*start;

	j = -1;
	i = 0;
	start = input;
	ret = ft_calloc(cmd_cnt + 1, sizeof(char *));
	if (ret == NULL)
		exit_session(shell, 1, "Memory error\nexit");
	while (input[++j])
	{
		if (input[j] == '\"' || input[j] == '\'')
			skip_quote(input, &j, input[j]);
		if (input[j] == '|')
		{
			ret[i++] = ft_substr(input, start - input, &input[j] - start);
			start = input + j + 1;
		}
		else if (input[j + 1] == '\0')
			ret[i++] = ft_substr(input, start - input, &input[j] - start + 1);
	}
	ret[i] = NULL;
	return (ret);
}
