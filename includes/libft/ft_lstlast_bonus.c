/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:50:13 by rel-mora          #+#    #+#             */
/*   Updated: 2024/07/29 12:18:46 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_command	*ft_lstlast(t_command *lst)
{

	t_command	*last;

	last = lst;
	if (!lst)
		return (NULL);

	while (last->next != NULL)
		last = last->next;
		
	return (last);
}
