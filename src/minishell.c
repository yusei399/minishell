#include "minishell.h"
//目的
	//envpをsplitして前と後ろに分けて線形リストに入れ
	//後でaccessコマンドで実行して実行できたらする
		// forkでプロセスを複製して実行する
void	shell_executive(t_shell *shell)
{
	if (lexer(shell))
	{
		printf("Invalid arg");
		free(shell->input);
	}
	else
	{
		executor(shell);
		free_all(shell);
	}
	add_history(shell->input);
}

void	minishell(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	(void)argc;
	ft_bzero(&shell, sizeof(t_shell));
	split_env(&shell, envp);
	shell = (t_shell){};
	g_status = 0;

	while (1)
	{
		shell.input = readline("minishell>$");
		executor(&shell);
		//lexerの上にheredoc
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
