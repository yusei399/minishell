
#include "../inc/minishell.h"

void	export(char *string)
{
	// errorを弾く
		//型式違いとか
	//戻り値で見れば良いのか??
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
