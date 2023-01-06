/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:44:39 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 15:33:19 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortthree(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (is_sorted(*stack_a))
		return ;
	if (head->index == 0)
	{
		rra(stack_a);
		swap_a(stack_a);
	}
	else if (head->index == 1 && head->next->index == 0)
		swap_a(stack_a);
	else if (head->index == 2 && head->next->index == 0)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (head->index == 1 && head->next->index == 2)
		rra(stack_a);
	else if (head->index == 2 && head->next->index == 1)
	{
		swap_a(stack_a);
		rra(stack_a);
	}
}

void	ft_sortfour(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 3)
	{
		if ((*stack_a)->next->index == 3)
			swap_a(stack_a);
		else
		{
			rotate_a(stack_a);
			rotate_a(stack_a);
		}
	}
	pb(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		ft_sortthree(stack_a);
	pa(stack_a, stack_b);
	rotate_a(stack_a);
}	

void	ft_sortfive(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 4)
	{
		if ((*stack_a)->next->index == 4)
			swap_a(stack_a);
		else if ((*stack_a)->next->next->index == 4)
		{
			rotate_a(stack_a);
			rotate_a(stack_a);
		}
		else
		{
			rra(stack_a);
			rra(stack_a);
		}
	}	
	pb(stack_a, stack_b);
	ft_sortfour(stack_a, stack_b);
	pa(stack_a, stack_b);
	rotate_a(stack_a);
}

void	ft_sortbig(t_list **stack_a, t_list **stack_b, int max_bits, int size)
{
	int		i;
	int		j;
	t_list	*head_a;

	i = 0;
	head_a = *stack_a;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
