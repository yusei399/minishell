/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 07:44:27 by susui             #+#    #+#             */
/*   Updated: 2022/10/19 18:39:05 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_check_char(char	c, char	charset)
{
	if (c == charset)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_word_num(char const	*str, char	c)
{
	int	i;
	int	word_num;

	word_num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_char(str[i], c) == 0
			&& ft_check_char(str[i + 1], c) == 1)
			word_num++;
		i++;
	}
	return (word_num);
}

void	ft_pushwords(char	*result, char const	*str, char	charset)
{
	int	i;

	i = 0;
	while (ft_check_char(str[i], charset) == 0)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
}

int	ft_makeresults(char **result, char const *str, char charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_char(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_check_char(str[i + j], charset) == 0)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!*result)
				return (1);
			ft_pushwords(result[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_num(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result[words] = 0;
	if (ft_makeresults(result, s, c))
	{
		while (words >= 0)
		{
			free(result[words]);
			words--;
		}
		free(result);
		return (NULL);
	}
	return (result);
}
