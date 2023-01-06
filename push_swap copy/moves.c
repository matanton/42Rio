/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:58:36 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:23 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack_one)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack_one) < 2)
		return (-1);
	head = *stack_one;
	next = head->next;
	if (!head && !next)
		printf("Error occured while swapping!");
	tmp_val = head->elem;
	tmp_index = head->index;
	head->elem = next->elem;
	head->index = next->index;
	next->elem = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	ft_rotate(t_list **stack_one)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack_one) < 2)
		return (-1);
	head = *stack_one;
	tail = ft_lstlast(head);
	*stack_one = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	ft_reverserotate(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	head = *stack_a;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack_a;
	*stack_a = tail;
	return (0);
}
