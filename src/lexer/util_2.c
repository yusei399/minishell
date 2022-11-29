#include "minishell.h"

size_t	count_arg_len(char *arg, t_list **val, t_list **key)
{
	size_t	len;
	t_list	*key_tmp;
	t_list	*val_tmp;

	key_tmp = *key;
	val_tmp = *val;
	len = ft_strlen(arg);
	while (key_tmp)
	{
		len -= (ft_strlen((char *)key_tmp->content) + 1);
		key_tmp = key_tmp->next;
	}
	while (val_tmp)
	{
		len += ft_strlen((char *)val_tmp->content);
		val_tmp = val_tmp->next;
	}
	return (len);
}

/*
	Copying lst content
*/
void	copy_lst_content(char **dst, size_t *j, t_list **lst)
{
	size_t	i;
	char	*val;

	i = 0;
	val = (char *)(*lst)->content;
	*lst = (*lst)->next;
	while (val[i])
	{
		(*dst)[*j] = val[i];
		(*j)++;
		i++;
	}
}

char	*create_expanded_arg(t_shell *data, char *arg, t_list **val, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;
	t_list	*val_tmp;

	i = 0;
	j = 0;
	val_tmp = *val;
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		exit_session(data, 1, "Memory error\nexit");
	while (arg[i] != '\"' && arg[i])
	{
		if (arg[i] == '$')
		{
			i += 1;
			copy_lst_content(&ret, &j, &val_tmp);
			while (ft_strchr("<>$\"\n \0", arg[i]) == NULL)
				i++;
		}
		else
			ret[j++] = arg[i++];
	}
	ret[j] = '\0';
	return (ret);
}