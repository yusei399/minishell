#include "../../inc/minishell.h"

void	formatter(t_shell *shell)
{
	char *txt;
}

int	main(int argc, char **argv, char **envp)
{
	char *ls[] = {"/bin/ls", NULL};
	printf("ls\n");
	execve(ls[0], ls, NULL);

	char *pwd[] = {"/bin/pwd", NULL};
	printf("pwd\n");
	execve(pwd[0], pwd, envp);
}