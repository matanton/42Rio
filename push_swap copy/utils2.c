/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:01 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 18:33:19 by matanton         ###   ########.fr       */
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

int	*ft_sort(int argc, char **data)
{
	int	*list;
	int	temp;
	int	i;
	int	j;

	i = -1;
	j = 0;
	list = malloc(sizeof(argc - 1));
	while (++j < argc)
		list[++i] = ft_atoi(data[j]);
	i = 0;
	while (i < argc - 2)
	{
		if (list[i + 1] < list[i])
		{
			temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (list);
}

void	put_index(int *array, t_list **list, int size_array)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	if (!list)
		return ;
	while (i < size_array)
	{
		*list = tmp;
		while (*list != NULL)
		{
			if ((*list)->elem == array[i])
			{
				(*list)->index = i;
				break ;
			}
			*list = (*list)->next;
		}
		i++;
	}
	*list = tmp;
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	ft_lastbit(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
