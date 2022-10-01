#include "../inc/minishell.h"

t_io	*redirect_last(t_io *io)
{
	if (io)
		while (io->next)
			io = io->next;
	return (io);
}

void	redirect_add_back(t_io **io, t_io *new)
{
	if (*io)
		redirect_last(*io)->next = new;
	else
		*io = new;
}

void	redirect_clear(t_io **io)
{
	t_io	*tmp;

	if (!io)
		return ;
	while (*io)
	{
		tmp = *io;
		*io = (*io)->next;
		free(tmp->data);
		free(tmp);
	}
}