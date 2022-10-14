#include	"../../inc/minishell.h"
#include	"../../inc/libft.h"

static int	go_home(t_shell *shell);

char	*ms_getenv(t_shell *data, char *name)
{
	t_env	*env_lst;

	env_lst = data->env;
	while (env_lst)
	{
		if (ft_strcmp(env_lst->key, name) == 0)
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return ("");
}

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
	if (chdir(ms_getenv(shell, "HOME")) != 0)
	{
		ft_putstr_fd("can't found $HOME\n", 1);
		return (1);
	}
	return (0);
}