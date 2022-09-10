/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:39:10 by susui             #+#    #+#             */
/*   Updated: 2022/07/20 18:21:57 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gl(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_1;
	size_t	len_2;

	i = 0;
	j = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (i < len_1)
		str[i++] = s1[j++];
	j = 0;
	while (j < len_2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

static char	*get_new(char *tmp)
{
	char	*str;
	size_t	i;

	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
	{
		free (tmp);
		return (NULL);
	}
	str = ft_substr(tmp, i + 1, ft_strlen(tmp));
	free(tmp);
	return (str);
}

static char	*trimer(char *tmp)
{
	char	*str;
	size_t	i;

	if (tmp[0] == '\0')
		return (NULL);
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	str = ft_substr(tmp, 0, i + 1);
	return (str);
}

static char	*read_line(int fd, char *tmp)
{
	ssize_t	n_read;
	char	*buf;

	n_read = 1;
	buf = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && n_read != 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[n_read] = '\0';
		tmp = ft_strjoin_gl(tmp, buf);
	}
	free (buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	tmp = read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	next = trimer(tmp);
	tmp = get_new(tmp);
	return (next);
}