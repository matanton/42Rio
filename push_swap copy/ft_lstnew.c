/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:13:35 by matanton          #+#    #+#             */
/*   Updated: 2023/01/05 14:09:30 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int elem)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node != NULL)
	{
		node->elem = elem;
		node->next = NULL;
	}
	return (node);
}

t_list	*ft_lstlast(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (list != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		return (tmp);
	}
	else
		return (NULL);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*list != NULL)
	{
		tmp = ft_lstlast(*list);
		tmp->next = new;
	}
	else
		*list = new;
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
