#include "../../inc/minishell.h"

char *ft_sign(char *in)
{
	char *sign;
	char *start;
	char *ret;

	sign = ft_strstr(in, "<<") + 2;
	while (*sign && *sign == ' ')
		sign++;
	start = sign;
	while (ft_strchr(" <>\0", *sign) == 0)
		sign++;
	ret = ft_substr(start, 0, sign - start);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

