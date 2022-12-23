/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:43:43 by matanton          #+#    #+#             */
/*   Updated: 2022/12/20 19:40:47 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*argto_stack(int argc, char **data)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (++i < argc)
		ft_lstadd_back(&list, ft_lstnew(ft_psatoi(data[i])));	
	return (list);
}

void	print_list(t_list **list)
{
	while (*list)
	{
		printf("stack: %i\n", (*list)->elem);
		*list = (*list)->next;
	}
}

