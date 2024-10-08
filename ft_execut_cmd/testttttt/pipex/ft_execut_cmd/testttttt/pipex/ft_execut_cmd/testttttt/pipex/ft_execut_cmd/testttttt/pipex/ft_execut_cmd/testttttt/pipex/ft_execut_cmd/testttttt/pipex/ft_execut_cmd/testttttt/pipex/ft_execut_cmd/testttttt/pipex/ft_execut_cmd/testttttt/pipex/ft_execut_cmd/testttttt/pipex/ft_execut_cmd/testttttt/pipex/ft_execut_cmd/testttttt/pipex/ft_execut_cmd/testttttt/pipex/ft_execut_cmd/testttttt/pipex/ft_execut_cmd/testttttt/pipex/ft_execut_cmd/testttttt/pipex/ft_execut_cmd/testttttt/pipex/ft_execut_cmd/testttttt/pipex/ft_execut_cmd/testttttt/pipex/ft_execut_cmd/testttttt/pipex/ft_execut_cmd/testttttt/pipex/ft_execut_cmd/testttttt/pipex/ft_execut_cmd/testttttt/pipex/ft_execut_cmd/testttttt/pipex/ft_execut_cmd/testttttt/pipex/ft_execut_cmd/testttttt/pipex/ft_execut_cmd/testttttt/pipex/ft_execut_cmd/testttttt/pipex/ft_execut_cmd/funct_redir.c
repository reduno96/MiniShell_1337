/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:33:07 by bouhammo          #+#    #+#             */
/*   Updated: 2024/08/19 11:57:55 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

char	*git_type_redir(t_redirect *redir)
{
	if (redir == NULL)
		return (NULL);
	else
	{	
		if (redir->type == REDIR_OUT)
			return (">");
		else if (redir->type == REDIR_IN)
			return ("<");
		else if (redir->type == DREDIR_OUT)
			return (">>");
		else if (redir->type == HERE_DOC)
			return ("<<");
		return (NULL);
	}
}
char 	**get_len(char **args , t_redirect *redir)
{
	int i;
	int count=0;
	char **new;

	i = 0;
	if(redir == NULL)
		count= 1;
	while(args[i] )
	{
		if(ft_strcmp(args[i], git_type_redir(redir)) == 0 )
		{
			i++;
			redir = redir->next;
		}
		else
			count++;
		i++;
	}
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	return (new);
}


char	**ft_new_args(char **args , t_redirect *redir)
{
	char **new;
	int i=0;
	int j=0;

	new = get_len(args , redir );
	while(args[i])
	{
		if(ft_strcmp(args[i], git_type_redir(redir) ) == 0)
		{
			i++;
			redir = redir->next;
		}
		else
		{
			new[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);	
}
int 	test_redir_here_doc(t_command *list)
{
	if (list == NULL)
		return (0);
	t_redirect *tmp;
	tmp = list->doc;
	while (tmp != NULL)
	{
		if (tmp->type == HERE_DOC || tmp->type == DREDIR_OUT || tmp->type == REDIR_OUT || tmp->type == REDIR_IN)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
