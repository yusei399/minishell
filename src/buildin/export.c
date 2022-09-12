
#include "../inc/minishell.h"

void	export(char *string)
{
	if (putenv(*string) == -1)
		return ;
}

// envp
//int main(int argc, char **argv, char **envp)
//{
//	printf("%s\n\n", argv[1]);
//	for (size_t i = 0; envp[i] ; i++)
//		printf("%s\n\n", envp[i]);
//}
