
#include "../inc/minishell.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i]=='=')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

// void	export(char *string)
// {
// 	// errorを弾く
// 		//型式違いとか
// 	//戻り値で見れば良いのか??
// 	if (putenv(*string) == -1)
// 		return ;
// }

// envp
//int main(int argc, char **argv, char **envp)
//{
//	printf("%s\n\n", argv[1]);
//	for (size_t i = 0; envp[i] ; i++)
//		printf("%s\n\n", envp[i]);
//}
