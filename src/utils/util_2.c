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

int	ft_isspace(char c)
{
	if ((c >= '\t' && *str <= '\r') || c == ' ')
		return (1);
	return (0);
}

char **alt_space_split(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
	return (ft_split(str, ' '));
}
