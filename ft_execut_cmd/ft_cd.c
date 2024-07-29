#include "../minishell.h"

void ft_cd(t_command *list)
{
	char *path ;

	while (list != NULL  && list->type == 32)
		list = list->next;
	
	if(ft_strcmp(list->str_input, "cd") == 0)
	{
		list = list->next;
			while (list != NULL  && list->type == 32)
				list = list->next;
			
			if (list == NULL)
			{
				path = getenv("HOME");
				if (chdir(path) == -1)
					perror("No such file or directory");
			}
			else
			{
				path = list->str_input;
				if (chdir(path) == -1)
					perror("No such file or directory");

			}
	}
}
