#include "../inc/minishell.h"
#include "../inc/libft.h"

t_quote	quote_init(char c, t_quote q)
{
	if (q == NONE)
	{
		if (c == '\'')
			return (SINGLE);
		else if (c == '\"')
			return (DOBULE);
	}
	else if (q == SINGLE)
	{
		if (c == '\'')
			return (NONE);
	}
	else if (q == DOBULE)
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

// int	main()
// {
// 	char s1[8] = "dfghjkl";
// 	// char *s_ptr = &s1;
// 	size_t n = 5;
// 	printf("%s",ft_strndup(s1, n));
// }
// lexer実装する
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

void	lexer(t_list **lst, char *c)
{
	size_t	i;
	size_t	head;
	t_quote	q;

	*lst = NULL;
	q = NONE;
	head = 0;
	i = 0;
	while (c[i]!= '\0')
	{
		if (ft_quote(c[i]))
			q = quote_init(c[i++], q);
		else if (q != NONE || ft_metachar(c[i]))
			i++;
		else
		{
			add(lst, c, head, &i);
			head = ++i;
		}
	}
	if (q != NONE)
		not_close(lst);
	else
		add(lst, c, head, &i);
}
