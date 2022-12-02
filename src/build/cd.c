#include "../../inc/minishell.h"

static int	go_home(t_shell *shell);

int	ft_cd(char *dir, t_shell *shell)
{
	if (dir == NULL || ft_strcmp(dir, "~") == 0)
		return (go_home(shell));
	else if (chdir(dir) != 0)
	{
		perror(dir);
		return (1);
	}
	return (0);
}

static int	go_home(t_shell *shell)
{
	if (chdir(ft_getenv(shell, "HOME")) != 0)
	{
		ft_putstr_fd("can't found $HOME\n", 1);
		return (1);
	}
	return (0);
}