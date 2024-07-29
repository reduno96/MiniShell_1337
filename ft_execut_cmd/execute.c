/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:46:31 by bouhammo          #+#    #+#             */
/*   Updated: 2024/07/29 09:24:17 by bouhammo         ###   ########.fr       */
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
	if(ft_strcmp(list->str_input, "exit") == 0)
		exit(0);
	
	ft_cd(list);
	ft_pwd(list);

}
	// (void) env;
	// int i = 0;
	// while (list !=  NULL)
	// {
	// 	printf("---===--> %s\n", list->str_input);
	// 	list = list->next;
	// }