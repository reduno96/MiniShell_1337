/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:08:06 by rel-mora          #+#    #+#             */
/*   Updated: 2024/07/29 09:24:37 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ff(void)
{
	system("leaks minishell");
}

int	main(int ac, char **av, char **env)
{
	char *str_input;
	t_command *x;
	
	x = NULL;
	while (1)
	{
		str_input = readline("minishell: ");
		if (!str_input)
			exit(1);
		add_history(str_input);
		ft_lexer(str_input, &x);
		
		ft_exute(x, env);
		
		free(x);
		x = NULL;
	}
	atexit(ff);
}