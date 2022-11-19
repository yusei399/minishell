#include "./../inc/minishell.h"
#include "./../inc/libft.h"

int	determine_input(char	*input, char **envp)
{
	if (strncmp(input, "/bin/", 5) == 0)
	{
		char *cmds[] = {input, NULL};
		execve(cmds[0], cmds, envp);
	}
	else
	{
		char *cmd = ft_strjoin("/bin/", input);
		char *cmds[] = {cmd, NULL};
		execve(cmds[0], cmds, envp);
	}
	return (0);
}

//目的
	//envpをsplitして前と後ろに分けて線形リストに入れ
	//後でaccessコマンドで実行して実行できたらする
		// forkでプロセスを複製して実行する


void	minishell(int argc, char **argv, char **envp)
{
	t_shell	shell;

	ft_bzero(&shell, sizeof(t_shell));
	split_env(&shell, envp);
	while (1)
	{
		shell.arg = readline("minishell>$");
		lexer(&shell);
		determine_input(shell.arg, envp);
		add_history(shell.arg);
		claen_cmd_list(&shell.cmd, free);
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		minishell(argc, argv, envp);
	return (1);
}
