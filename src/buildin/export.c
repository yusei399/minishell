
#include "../../inc/minishell.h"
#include "../../inc/libft.h"

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

int	check_env(char *str, char *env)
{
	int	size;
	int	i;

	i = 0;
	size = len(str);
	if (size == -1)
		return (-2);
	while (env[i])
	{
		while (ft_memcmp(env[i], str, size + 1))
			return (i);
		i++;
	}
	return (-1);
}

char	**minus(char **env, int i, char *str)
{
	free(env[i]);
	env[i] = ft_strdup(str);
	return (env);
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
