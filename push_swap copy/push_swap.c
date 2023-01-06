/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:34:19 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 17:24:44 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = ft_lastbit(stack_a);
	if (size == 2)
		rotate_a(stack_a);
	if (size == 3)
		ft_sortthree(stack_a);
	if (size == 4)
		ft_sortfour(stack_a, stack_b);
	if (size == 5)
		ft_sortfive(stack_a, stack_b);
	if (size > 5)
		ft_sortbig(stack_a, stack_b, max_bits, size);
}

int	main(int argc, char **data)
{
	t_list	*list;
	t_list	*listb;
	int		*array;

	if (argc > 1)
	{
		if (is_long(argc, data))
			return (ft_error());
		if (is_number(argc, data) && !is_repeated(argc, data))
		{
			list = argto_stack(argc, data);
			if (is_sorted(list))
				return (1);
			array = ft_sort(argc, data);
			put_index (array, &list, argc - 1);
			push_swap (&list, &listb);
		}
		else
			return (ft_error());
	}
	else
		return (1);
}
