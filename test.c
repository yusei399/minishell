#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	find_equal(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if(string[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char


int main(int argc, char **argv, char **envp)
{
	for (size_t i = 0; envp[i] ; i++)
		printf("envp: %s\n", envp[i]);
	char str[] = "12345=324";
	size_t where = find_equal(str);
	printf("%zu\n", where);
}