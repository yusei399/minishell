#include "../../inc/minishell.h"

// piepを取り除いた文字列を返す

int is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

size_t	pipe_len(char *arg)
{
	size_t	i;

	i = 0;
	while(arg[i] != '|' && arg[i])
		i++;
	return (i);
}
char	*extract_pipe(char *arg, int n)
{
	int		pipe_count;
	int		i;
	char	*str;

	pipe_count = 0;
	i = 0;
	// i個目のパイプまでの文字列
	// pipeをカウントして pipe_count == iになった場所 +1の部分からパイプまでを新たな文字列にする
	while (n != pipe_count && arg[i])
	{
		if (is_pipe(arg[i]))
			pipe_count++;
		i++;
	}
	// arg[i]の位置から次のpipeもしくはNULLまでを取る
	str = ft_strndup(&arg[i], pipe_len(&arg[i]));
	if (!str)
		return (NULL);
	return (str);
}
int	pipe_init(t_shell *shell, size_t pipe_count)
{
	//パイプまでの文字をコマンドに入れる
	t_cmd	*cmd;
	int		i;

	cmd = shell->cmd;
	i = 0;
	if (pipe_count == 0)
	{
		cmd->command = shell->arg;
		return (0);
	}
	while (cmd)
	{
		cmd->command = extract_pipe(shell->arg, i);
		i++;
		cmd = cmd->next;
	}
	return (0);
}

int	add_pipe_list(t_shell *shell, size_t pipe_count)
{
	size_t	i;
	t_cmd	*new;

	i = 0;
	while(i <= pipe_count)
	{
		new = lstnew();
		if (!new)
			return (1);
		lstadd_back(&shell->cmd, new);
		// nullが帰ってきたとき(失敗した時)にfreeしなきゃ
		i++;
	}
	printf("\tlist size: %zu\n", i); // todo
	return (0);
}


int	pipe_count(t_shell *shell)
{
	int	pipe_count;
	int	i;

	pipe_count = 0;
	i = 0;

	if (shell->arg[0] == '|')
		return (-1);
	while (shell->arg[i])
	{
		if (shell->arg[i] == '|')
		{
			if (shell->arg[i + 1] == '|' || !shell->arg[i + 1])
				return (-1);
			pipe_count++;
		}
		i++;
	}
	return (pipe_count);
}

void	check1(t_shell *shell, int number, int	p_count)
{
	if (number == 1)
	{
		printf("\x1b[36m%s\x1b[0m", "<<<<check start>>>>>>>>\n");
		printf("\x1b[36mpipe count : %d\n\x1b[0m", p_count);
	}
	if (number == 2)
	{
		t_cmd *cmd = shell->cmd;
		size_t size = 1;
		printf("\x1b[36mFull argument is: %s\n\x1b[0m", shell->arg);
		while (cmd)
		{
			printf("\t%zu arg is : %s\n", size, cmd->command);
			size++;
			cmd = cmd->next;
		}
		printf("\x1b[36m%s\x1b[0m", "---------------------------\n");
	}
}

int 	pipe_split(t_shell *shell)
{
	int	p_count;

	p_count = pipe_count(shell);
	check1(shell, 1, p_count); // todo delete
	if (p_count == -1)
		return (1);
	add_pipe_list(shell, p_count); // todo OKっぽい
	// lst->cmd に アーギュメントを入れていく
	pipe_init(shell, p_count); // todo ok
	check1(shell, 2, p_count); //todo delete
	return (0);
}

// gcc pipe_split.c ../../libft/libft.a ../cmd_lstope/*

 /* -----------------------------------------------------------------------
int	main(int argc, char **argv)
{
	t_shell shell;
	t_cmd *cmd;
	size_t size = 1;
	int i = 0;

	if (argc == 1)
		return (1);
	memset(&shell,0,sizeof(t_shell));
	shell.arg = argv[1];
	pipe_split(&shell);
	printf("\x1b[36mFull argument is: %s\n\x1b[0m", shell.arg);
	cmd = shell.cmd;
	while (cmd)
	{
		printf("\t%zu arg is : %s\n", size, cmd->command);
		size++;
		cmd = cmd->next;
	}
	return (0);
}
 ----------------------------------------------------------------------- */

// todo パイプのあとにスペースがあってその後にまたパイプのときの処理
	//todo → "cat | | ls"
// todo パイプのあとのスペースを消す
	// todo フォーマットするときでいいか
// todo コマンドの free

