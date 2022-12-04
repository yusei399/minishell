/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:32 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/12/04 11:24:33 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
◦ << にデリミタを与えて、そのデリミタを含む行が見えるまで入力を読むようにします。
	しかし、それは履歴を更新する必要はありません!
*/
/*----------------------out put--------------------------*/
void	output_list(t_list *herelist)
{
	int		fd;
	char	*line;
	t_list	*list;
//	oepn
	list = herelist;
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR, 0644);
	if (fd < 0)
		return ;
//	書き込む
	while (list)
	{
		line = list->content;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		list = list->next;
	}
}
/*-------------------------------------------------------*/


/*--------------------input-------------------------------*/

 static int	ft_isspace(char c)
 {
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	 return (0);
 }

char	*get_end(char *arg)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (arg[i] && count < 2)
	{
		if (arg[i] == '<')
			count ++;
		i++;
	}
	while (ft_isspace(arg[i]))
		i++;
	return(ft_strdup(&arg[i]));
}

static int is_exact_match(char *input, char *end)
{
	if (ft_strlen(input) != ft_strlen(end))
		return (0);
	if (ft_strncmp(input, end, ft_strlen(end)) != 0)
		return (0);
	return (1);
}

int	check_input(char *input, char *end)
{
	if (!input)
		return (1);
	if (is_exact_match(input, end))
		return (1);
	return (0);
}

t_list	*get_input(t_list *herelist, char *end)
{
	char	*input;
	char	*str;
	t_list	*new;
	// 受け取った input がend になるまで
	while (1)
	{
		input = readline("> ");
		if (check_input(input, end))
			return (herelist);
		str = ft_strdup(input);
		if (!str)
			return (herelist);
		new = ft_lstnew(str);
		if (!new)
			return (herelist);
		ft_lstadd_back(&herelist, new);
	}
}
/*-------------------------------------------------------------*/

/*-------------------------check------------------------------*/
int	check_haredoc(char *arg)
{
	if (ft_strstr(arg, "<<") == NULL)
		return (1);
	return (0);
}
/*-----------------------------------------------------------*/

void	treat_heredoc(t_shell *shell)
{
	char	*end;
	t_list	*herelist;

	herelist = malloc(sizeof(t_list));
	ft_bzero(&herelist, sizeof(t_list));
	// 文字が << だったときに呼ばれると仮定する? or 確認する??
	if (check_haredoc(shell->input)) //todo[done]
		return ;
	end = get_end(shell->input);
	if (!end)
		return ;
	// 終了文字が来るまで文字を読み続ける
	herelist = get_input(herelist, end); //todo [ok]
	free(end);
	output_list(herelist);
	ft_lstclear(&herelist, free);
}

/*
int main(int argc, char **argv)
{
	t_shell shell;
	shell.arg = argv[1];
	treat_heredoc(&shell);
}
*/







/* ---------------------------------------------------------------------------
int open_test(char *filename, char *contents)
{
	int	fd;

	// O_CREAT -> ファイルが存在しなかった場合は作成 (create) する
	fd = open(filename,  O_RDWR | O_CREAT);
	if (fd == -1)
	{
		printf("error");
		return 1;
	}
	write(fd, contents, strlen(contents));
	close(fd);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 3)
		open_test(argv[1], argv[2]);
	else
	{
		printf("need 3 arg\n");
		printf("\x1b[36m%s\x1b[0m", "xx filename contents\n");
	}
	return 0;
}


// get input test
int main()
{
	t_list	*herelist;
	ft_bzero(&herelist, sizeof(t_list));
	herelist = get_input(herelist, "end");
	while(herelist)
	{
		printf("contents is : %s\n", (char *)herelist->content);
		herelist = herelist->next;
	}
}



--------------------------------------------------------------------------- */
