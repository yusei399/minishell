#include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	if (argc == 1 && argv)
		printf("%s", "最終関数呼び出し");
	else
	{
		ft_putstr_fd("minishell", 2);
		ft_putstr_fd("invalid arg",2);
	}
	return 0;
}
