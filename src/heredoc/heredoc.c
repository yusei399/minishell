#include "../../inc/minishell.h"

/*
◦ << にデリミタを与えて、そのデリミタを含む行が見えるまで入力を読むようにします。
	しかし、それは履歴を更新する必要はありません!
◦ >> は append モードで出力をリダイレクトする必要があります
*/
/*

void	treat_heredoc(t_shell	*shell)
{
}
*/

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
