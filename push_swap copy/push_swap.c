/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:34:19 by matanton          #+#    #+#             */
/*   Updated: 2023/01/09 16:51:32 by matanton         ###   ########.fr       */
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

void	free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list->next != NULL)
	{
		list = list->next;
		free (tmp);
		tmp = NULL;
		tmp = list;
	}
	free (list);
	list = NULL;
}

int	main(int argc, char **data)
{
	t_list	*list;
	t_list	*listb;
	int		*array;

	list = NULL;
	listb = NULL;
	if (argc > 1)
	{
		if (is_num(argc, data) && !is_rep(argc, data) && !is_long(argc, data))
		{
			list = argto_stack(argc, data);
			if (is_sorted(list))
			{
				free_list (list);
				return (1);
			}
			array = ft_sort(argc, data);
			put_index (array, &list, argc - 1);
			free (array);
			push_swap (&list, &listb);
			free_list (list);
		}
		else
			return (ft_error());
	}
}
