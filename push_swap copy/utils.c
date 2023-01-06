/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:43:43 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 17:26:42 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack_a)
{
	if (ft_reverserotate(stack_a) == -1)
		return (-1);
	write (1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (ft_reverserotate(stack_b) == -1)
		return (-1);
	write (1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	ft_reverserotate(stack_a);
	ft_reverserotate(stack_b);
	write (1, "rrr\n", 4);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write (1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write (1, "pb\n", 3);
	return (0);
}
