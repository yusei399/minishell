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
	while(i < pipe_count)
	{
		new = lstnew();
		if (!new)
			return (1);
		lstadd_back(&shell->cmd, new);
		// nullが帰ってきたとき(失敗した時)にfreeしなきゃ
		printf("list size: %zu\n", i); // todo
		i++;
	}
	printf("\n\n"); // todo
	return (0);
}

// todo --------------------------
// []pipeで終わってるとき -> errorっぽいな
// []pipe2連のときの対処 わからん

int	pipe_count(t_shell *shell)
{
	int	pipe_count;
	int	i;

	pipe_count = 0;
	i = 0;
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

int 	pipe_split(t_shell *shell)
{
	int	p_count;

	p_count = pipe_count(shell);
	printf("pipe count : %d\n", p_count); //  todo OK
	if (p_count == -1)
		return (1);
	add_pipe_list(shell, p_count); // todo OKっぽい
	// lst->cmd に アーギュメントを入れていく
	pipe_init(shell, p_count); // todo -[segv]-
	return (0);
}

 /* -----------------------------------------------------------------------
int	main(int argc, char **argv)
{
	t_shell shell;
	t_cmd *cmd;
	int i;

	memset(&shell,0,sizeof(t_shell));
	shell.cmd = lstnew();
	if (argc == 1)
		return (1);
	i = 0;
	cmd = shell.cmd;
	shell.arg = argv[1];
	pipe_split(&shell);
	size_t size = 1;
	printf("Full argument is: %s\n", shell.arg);
	while (cmd)
	{
		printf("%zu arg is : %s\n", size, cmd->command);
		size++;
		cmd = cmd->next;
	}
	return (0);
}
 ----------------------------------------------------------------------- */

//最後のにNULLが入ってない