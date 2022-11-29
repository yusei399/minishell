#include "minishell.h"

static char	*get_abs_exe(char *file, char **paths);
static void	free_dp(char **dp);

int	ft_execvp(char *file, char *argv[], t_shell *shell)
{
	char		**paths;

	paths = ft_split(ms_getenv(shell, "PATH"), ':');
	file = get_abs_exe(file, paths);
	if (file == NULL)
		return (-1);
	free_dp(paths);
	execve(file, argv, NULL);
	return (-1);
}

static char	*get_abs_exe(char *file, char **paths)
{
	char	*tmp;
	char	*abs;
	int		i;

	if (access(file, X_OK) == 0)
		return (file);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		abs = ft_strjoin(tmp, file);
		free(tmp);
		if (access(abs, X_OK) == 0)
			return (abs);
		else
			free(abs);
		i++;
	}
	return (NULL);
}

static void	free_dp(char **dp)
{
	size_t	i;

	i = 0;
	while (dp[i])
		free(dp[i++]);
	free(dp);
}