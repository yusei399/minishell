#include "../../inc/minishell.h"

void	save_redirect(t_shell *shell)
{
	size_t	i;
	size_t	j;
	t_cmd	*tmp;

	i = 0;
	j = 0;
	// ft_isdelimiter()で< などが存在するか確かめる
	while (shell->cmd[i])
	{
		tmp = shell->cmd[i];
		while (tmp->command[j])
		{
			// <<
			if (ft_strchr(tmp->command[j], '<') && ft_strchr(tmp->command[j++], '<'))
			{
			}
			// <
			else if (ft_strchr(tmp->command[j], '<'))
			{}
			// >>
			else if (ft_strchr(tmp->command[j], '>') && ft_strchr(tmp->command[j++], '>'))
			{}
			// >
			else if (ft_strchr(tmp->command[j], '<'))
			{}
			j++;
		}
		i++;
	}
	return ;
}