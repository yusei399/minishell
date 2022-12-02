#include "../../inc/minishell.h"

char	*store_quoted_arg(t_shell *shell, char *input, size_t *i, char quote)
{
	size_t	len;
	char	*arg;

	len = 0;
	*i += 1;
	while (input[*i] != quote)
	{
		(*i)++;
		len++;
	}
	if (quote == '\"')
		arg = expand_env(&input[*i - len], shell, true);
	else
		arg = ft_substr(input, *i - len, len);
	if (arg == NULL)
		return (NULL);
	return (arg);
}

char	*extract_arg(t_shell *shell, char *input, char **start, size_t *i)
{
	char	*arg;
	char	*ret;

	ret = NULL;
	if (**start == '$')
		arg = expand_env(*start, shell, false);
	else if (input[*i + 1] == '\0')
		arg = ft_substr(input, *start - input, &input[*i] - *start + 1);
	else
		arg = ft_substr(input, *start - input, &input[*i] - *start);
	if (arg == NULL)
		exit_session(shell, 1, "Memory error\nexit");
	ret = ft_strtrim(arg, " ");
	free(arg);
	if (ret == NULL)
		exit_session(shell, 1, "Memory error\nexit");
	if (*ret == '$')
	{
		arg = expand_env(ret, shell, false);
		free(ret);
		ret = arg;
	}
	*start = input + *i + 1;
	return (ret);
}