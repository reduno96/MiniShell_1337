#include "../minishell.h"

void ft_pwd(t_command *list)
{
	char *path ;

		while (list != NULL  && list->type == 32)
			list = list->next;

		if(ft_strcmp(list->str_input, "pwd") == 0 || ft_strcmp(list->str_input, "PWD") == 0)
		{
			 path = getcwd(NULL, 0);
			if(path == NULL)
				return ;
			printf("%s\n", path);
		}
	
}