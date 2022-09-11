#include "../inc/minfthell.h"

int	ft_delimiter(char c)
{
	if ((c == '|') || (c == '<') || (c == '>'))
		return 1;
	return 0;
}

int	ft_metachar(char c)
{
	if (ft_blank(c) || ft_delimiter(c))
		return 1;
	return 0;
}