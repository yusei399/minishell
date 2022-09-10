
#include "minishell.h"

void pwd(void)
{
	char buf[BUFSIZ];
	if(getcwd(buf, sizeof(buf)) != NULL)
		printf("%s\n", buf);
}
