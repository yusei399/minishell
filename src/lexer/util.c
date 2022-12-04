/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:25:02 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 12:26:04 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
		write(1, s++, 1);
	write(1, "\n", 1);
	return ;
}

void	exit_session(t_shell *data, int status, char *msg)
{
	(void)data;
	g_status = status;
	exit_(msg, ft_itoa(g_status));
}

void	ft_quote(char *input, size_t *i, char quote)
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

static size_t	ft_check_len(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
		len++;
	}
	return (len);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == needle[0])
			len = ft_check_len(haystack, needle);
		if (len == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
