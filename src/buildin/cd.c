

#include	"../../inc/minishell.h"
#include	"../../inc/libft.h"

void	error_msg(char **argv)
{
	ft_putstr_fd("cd :", 2);
	if (argv[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(argv[1], 2);
}

void	ft_cd(char	*path)
{
	chdir(path);
}

