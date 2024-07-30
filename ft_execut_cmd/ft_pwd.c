#include "../minishell.h"

void ft_pwd(t_command *list)
{
	char *path ;
		while (list != NULL  && list->type == 32)
			list = list->next;


			path = getcwd(NULL, 0);
			if(path == NULL)
				return ;
			printf("%s\n", path);	
}