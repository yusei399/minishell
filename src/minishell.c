#include "../inc/minishell.h"
//目的
	//envpをsplitして前と後ろに分けて線形リストに入れ
	//後でaccessコマンドで実行して実行できたらする
		// forkでプロセスを複製して実行する
void	shell_executive(t_shell *shell)
{
	treat_heredoc(shell);
	if (lexer(shell))
	{
		printf("Invalid arg\n");
		free(shell->input);
	}
	else
	{
		executor(shell);
		free_all(shell);
	}
}

void	minishell(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	(void)argc;
	ft_bzero(&shell, sizeof(t_shell));
	shell = (t_shell){};
	g_status = 0;
	signal(SIGINT, &handle_signal);
	signal(SIGQUIT, SIG_IGN);
	shell.envp = envp;
	split_env(&shell, envp);
	while (1)
	{
		shell.input = readline("minishell>$");
		if (shell.input == NULL)
			exit_("\b\bexit", EXIT_SUCCESS);
		if (shell.input[0])
			add_history(shell.input);
		if (shell.input[0] != '\0')
			shell_executive(&shell);
		else
			free(shell.input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		minishell(argc, argv, envp);
	return (1);
}
