/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:46 by susui             #+#    #+#             */
/*   Updated: 2022/10/22 11:47:48 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
int	quote_init(char c, int q)
{
	if (q == NONE)
	{
		if (c == '\'')
			return (SINGLE);
		else if (c == '\"')
			return (DOUBLE);
	}
	else if (q == SINGLE)
	{
		if (c == '\'')
			return (NONE);
	}
	else if (q == DOUBLE)
	{
		if (c == '\"')
			return (NONE);
	}
	return (q);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (n < len)
		len = n;
	result = (char *)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	add(t_list **lst, char *c, size_t head, size_t *i)
{
	char	*tmp;

	if (head < *i || *c == '\0')
	{
		tmp = ft_strndup(&c[head], *i - head);
		ft_lstadd_back(lst, ft_lstnew(tmp));
	}
	if (ft_delimiter(c[*i]))
	{
		if (ft_redirect(c[*i], c[*i + 1]))
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strndup(&c[*i], 2)));
			*i += 1;
		}
		else
			ft_lstadd_back(lst, ft_lstnew(ft_strndup(&c[*i], 1)));
	}
}

void	not_close(t_list **lst)
{
	ft_lstclear(lst, self_free);
	*lst = NULL;
}

void	lexer(t_list **lst, char *str)
{
	size_t	i;
	size_t	head;
	int		q;

	*lst = NULL;
	q = NONE;
	head = 0;
	i = 0;
	while (str[i] != '\0')
	{
		// クオート系の文字があったら
		if (ft_isquote(str[i]))
		{
			q = quote_init(str[i], q);
			i++;
		}
		else if (q != NONE || ft_ismetachar(str[i]))
			i++;
		else
		{
			add(lst, str, head, &i);
			head = ++i;
		}
	}
	if (q != NONE)
		not_close(lst);
	else
		add(lst, str, head, &i);
}
*/

void	pipe_split()
{

}

int 	lexer(t_shell *shell)
{
	pipe_split(shell);
	if (quatecheck(shell))
		return 1;
	save_redirect();

	return 0;
}

int main(int argc, char **argv)
{
	t_shell shell;

	if (argc != 2)
		return 0;
	shell.arg = argv[1];
	lexer(&shell);
	shell.arg = "sdfghjksdfghjk''";
	lexer(&shell);
}