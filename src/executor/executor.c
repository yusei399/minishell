#include "minishell.h"

static	void	exe_loop(t_shell *shell, int *tmpout, pid_t *pid);
static bool	ft_built(char *file, char **argv, t_shell *shell);
static void	operate_outfile(t_shell *shell, int *tmpout);
static	void	execute(t_shell *shell, pid_t *pid, int i);

void	executor(t_shell *shell)
{
	int		tmpin;
	int		tmpout;
	pid_t	pid;

	tmpin = dup(0);
	tmpout = dup(1);
	if (shell->cmd->fd_in)
		shell->cmd->fd[IN] = open(shell->cmd->fd_in, O_RDONLY);
	else
		shell->cmd->fd[IN] = dup(tmpin);
	exe_loop(shell, &tmpout, &pid);
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	close(shell->cmd->fd[OUT]);
	wait_processes(shell);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &handle_signal);
}

static	void	exe_loop(t_shell *shell, int *tmpout, pid_t *pid)
{
	u_int32_t	i;

	i = 0;

	while (i < shell->cmd->cmd_cnt)
	{
		dup2(shell->cmd->fd[IN], 0);
		close(shell->cmd->fd[IN]);
		if (i == shell->cmd->cmd_cnt - 1)
			operate_outfile(shell, tmpout);
		else
		{
			pipe(shell->cmd->pipe);
			shell->cmd->fd[IN] = shell->cmd->pipe[IN];
			shell->cmd->fd[OUT] = shell->cmd->pipe[OUT];
		}
		dup2(shell->cmd->fd[OUT], 1);
		close(shell->cmd->fd[OUT]);
		execute(shell, pid, i);
		i++;
	}
}

static	void	execute(t_shell *shell, pid_t *pid, int i)
{
	char	*file;
	char	**argv;

	file = shell->cmd->commands[i].argv[0];
	argv = shell->cmd->commands[i].argv;
	if (file == NULL)
		return ;
	if (ft_built(file, argv, shell) == true)
		return ;
	else
	{
		*pid = fork();
		signal(SIGQUIT, &handle_signal);
		signal(SIGINT, SIG_IGN);
		if (*pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			close(shell->cmd->fd[IN]);
			if (ft_execvp(file, argv, shell) != 0)
				perror(file);
			exit(127);
		}
	}
}

static bool	ft_built(char *file, char **argv, t_shell *shell)
{
	if (ft_strcmp(file, "echo") == 0)
		g_status = ft_echo(argv);
	else if (ft_strcmp(file, "env") == 0)
		ft_env(shell);
	else if (ft_strcmp(file, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(file, "cd") == 0)
		g_status = ft_cd(argv[1], shell);
	else if (ft_strcmp(file, "exit") == 0)
		exit(1);
	else if (ft_strcmp(file, "export") == 0)
		g_status = ft_export(shell, argv[1]);
	else if (ft_strcmp(file, "unset") == 0)
		ft_unset(shell, argv[1]);
	else
		return (false);
	return (true);
}

static void	operate_outfile(t_shell *shell, int *tmpout)
{
	if (shell->cmd->fd_out)
	{
		if (shell->cmd->outfile_mode == TRUNC)
			shell->cmd->fd[OUT] = open(shell->cmd->fd_out,
					O_RDWR | O_CREAT | O_TRUNC, 0644);
		else if (shell->cmd->outfile_mode == APPEND)
			shell->cmd->fd[OUT] = open(shell->cmd->fd_out,
					O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
		shell->cmd->fd[OUT] = dup(*tmpout);
}