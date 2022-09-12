#include "../inc/minfthell.h"

int	ft_name(char c)
{
	if (ft_ftdigit(c) || ft_ftalpha(c) || c == '_')
		return 1;
	return 0;
}

int	ft_redirect(char c1, char c2)
{
	if ((c1 == '<' && c2 == '<')
		|| (c1 == '>' && c2 == '>'))
		return 1;
	return 0;
}

int	ft_heredoc(char *c)
{
	if (c[0] == '<' && c[1] == '<')
		return 1;
	return 0;
}

int	ft_quote(char c)
{
	if (c == '\'' || c == '\"')
		return 1;
	return 0;
}

int	ft_blank(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	return 0;
}

