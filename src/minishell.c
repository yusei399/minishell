#include "minishell.h"
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
		shell.input = readline("minishell>$");
		split_env(&shell, envp);
		executor(&shell);
		treat_heredoc(&shell);
		lexer(&shell);
		// determine_input(shell.arg, envp);
		add_history(shell.arg);
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		minishell(argc, argv, envp);
	return (1);
}
