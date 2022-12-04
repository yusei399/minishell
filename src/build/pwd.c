#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	ft_putendl(cwd);
}
