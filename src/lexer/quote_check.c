
#include "../../inc/minishell.h"

// tmp ----------------------------------------------------------------------------
int	ft_isquote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}
// --------------------------------------------------------------------------------
int	isclose(char *arg)
{
	char  	quot;
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	quot = arg[i++];
	while (arg[i])
	{
		if (ft_isquote(arg[i]) && arg[i -1] != '\\')
			last++;
		i++;
	}
	printf("last quate distenation is: %zu\n", last);
	printf("dest is: %zu\n", i);
	if (last != 0 && arg[last] == quot)
		return (0);
	return (1);
}

int	is_even_quate(char *arg)
{
	int		i;
	int		even_count;
	char	quate;
	// 閉じられてる確認は下から、最初に位置のクオートが偶数化どうか判定する
	even_count = 1;
	i = 0;
	quate = arg[i++];
	while (arg[i])
	{
		if (arg[i] == quate && arg[i - 1] != '\\')
			even_count++;
		i++;
	}
	printf("even count : %d\n", even_count);
	return (even_count % 2);
}

int	get_first_quate(char *arg)
{
	size_t	i;
	int		quot;

	i = 0;
	quot = -1;
	while (arg[i])
	{
		if (quot == -1 && ft_isquote(arg[i]))
			quot = i;
		i++;
	}
	return (quot);
}

int	quatecheck(t_shell *shell)
{
	int		quot;

	quot = get_first_quate(shell->arg);
	// quot が存在していたら 閉じられているかを確認したい
	if (quot == -1)
		return (0);
	if (isclose(&shell->arg[quot]))
	{
		printf("isn't closed\n");
		return (1);
	}
	if (quot != -1 && is_even_quate(&shell->arg[quot]))
	{
		printf("no\n");
		return (1);
	}
	printf("ok\n");
	return 0;
}

//todo[] PDFをもらう
