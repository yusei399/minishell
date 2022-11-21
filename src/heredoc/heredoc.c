#include "../../inc/minishell.h"

/*
◦ << にデリミタを与えて、そのデリミタを含む行が見えるまで入力を読むようにします。
	しかし、それは履歴を更新する必要はありません!
*/
/*----------------------out put--------------------------*/
void	output_list()
{

}
/*-------------------------------------------------------*/


/*--------------------input-------------------------------*/
int is_exact_match(char *input, char *end)
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
}

void	get_input(t_list *herelist, char *end)
{
	char	*input;
	t_list	*new;
	// 受け取った input がend になるまで
	while (1)
	{
		input = readline("> ");
		if (check_input(input, end))
			return ;
		new = ft_lstnew();
		if (!new)
			return (1);
		ft_lstadd_back(herelist, new);
	}
}
/*-------------------------------------------------------------*/

/*-------------------------check------------------------------*/
int	check_haredoc((t_shell *shell))
{

}
/*-----------------------------------------------------------*/

void	treat_heredoc(t_shell *shell)
{
	t_list	*herelist;
	// 文字が << だったときに呼ばれると仮定する? or 確認する??
	if (check_haredoc(shell))
		return ;
	// 終了文字が来るまで文字を読み続ける
	get_input(herelist, end);
	// 出力する
	output_list();
	// listを壊す
	ft_lstclear(&herelist, free);
}













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
--------------------------------------------------------------------------- */
