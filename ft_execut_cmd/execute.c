/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:46:31 by bouhammo          #+#    #+#             */
/*   Updated: 2024/07/29 15:36:28 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void  ft_exute( t_command *list , char **env)
{

	(void) env;
	if (list == NULL)
		return ;
	while (list && list->type == 32)
		list = list->next;
	
	// printf("list->str_input = %s\n", list->str_input);
	if(ft_strcmp(list->str_input, "exit") == 0)
		exit(0);
		
	else if(ft_strcmp(list->str_input, "cd") == 0)
		ft_cd(list);
		
	else if (ft_strcmp(list->str_input, "pwd") == 0 || ft_strcmp(list->str_input, "PWD") ==0 )
		ft_pwd(list);

	else
	{

		int pid = fork();
		char **argv;
		if(pid < 0)
			perror("fork");
		else if(pid == 0)
		{
			t_command *elem = NULL;
			while (list )
			{
				if(list->type == -1)
				{
					t_command *node = ft_lstnew(list->str_input, list->len, list->type, list->state);
					ft_add(&elem, node);
					
				}
				list = list->next;
			}
			argv = create_argv(elem);
			
			char *ptr = path_command(argv[0]);
			if (!ptr)
			{
				printf("command not found\n");
				exit(127);
			}

			if (access(ptr, X_OK) == -1)
				exit(126);
			if(execve(ptr, argv, NULL) == -1)
				perror("execve");
		}
		else
		{
			int status;
			if(wait(&status) == -1)
				perror("wait");
		}
		




}
			// t_command *ptr;
			// ptr = elem;
			// while (ptr !=  NULL)
			// {
			// 	printf(" ---> %s\n", ptr->str_input);
			// 	ptr = ptr->next;
			// }
	}


	
	// (void) env;
	// int i = 0;
	// while (list !=  NULL)
	// {
	// 	printf("---===--> %s\n", list->str_input);
	// 	list = list->next;
	// }