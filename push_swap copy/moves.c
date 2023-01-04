/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:58:36 by matanton          #+#    #+#             */
/*   Updated: 2023/01/03 15:39:19 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack_one)
{
	int	tmp;
	int	tmp_index;

	tmp = (*stack_one)->elem;
	tmp_index = (*stack_one)->index;
	(*stack_one)->elem = (*stack_one)->next->elem;
	(*stack_one)->index = (*stack_one)->next->index;
	(*stack_one)->next->elem = tmp;
	(*stack_one)->next->index = tmp_index;
}

void	ft_rotate(t_list **stack_one)
{
	t_list	*list;
	t_list	*tmp;

	tmp = (*stack_one);
	list = tmp->next;
	
	while ((*stack_one) != NULL)
	{
		if ((*stack_one)->next == NULL)
		{	
			(*stack_one)->next = tmp;
			tmp->next = NULL;
		}	
		(*stack_one) = (*stack_one)->next;
	}
	(*stack_one) = list;
}

void	ft_push(t_list **stack_one, t_list **stack_two)
{
	t_list	*tmp;
//	t_list	*tmp2;

	if ((*stack_two) == NULL)
		return ;
	
	tmp = (*stack_one);
	(*stack_one) = tmp->next;
	tmp->next = (*stack_two);
	(*stack_two) = tmp;
	
/*	tmp2 = (*stack_one)->next;

	(*stack_one)->next = (*stack_two);
	(*stack_two) = (*stack_one);
	(*stack_one) = tmp->next;
*/
}

void swap_a(t_list **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void swap_b(t_list **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}
