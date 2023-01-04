/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:34:19 by matanton          #+#    #+#             */
/*   Updated: 2023/01/03 15:39:55 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **data)
{
	int	i;
	
	i = -1;
	if (argc > 2)
	{
		t_list	*list;
		t_list	*listb;
		int		*array;

		if (is_long(argc, data))
		{
			write(1, "numero fora dos limites min_int e max_int\n", 43);
			return (1);
		}	
		if (is_number(argc, data) && !is_repeated(argc, data))
		{
			//write (1, "OK\n", 3);
			list = argto_stack(argc, data);
			listb = argto_stack(argc, data);
			if (is_sorted(*list))
				write (1, "is sorted\n", 10);
			array = ft_sort(argc, data);
			put_index(array, &list, argc - 1);
			swap_a(&list);
			ft_rotate(&list);
			ft_push(&list, &listb);
			//printf("elem= %i",list->elem);
			while (list != NULL)
			{
				printf("index= %i\t", list->index);
				printf("elem= %i\n", list->elem);
				list = list->next;
			}
			while (listb != NULL)
			{
				printf("indexb= %i\t", listb->index);
				printf("elemb= %i\n", listb->elem);
				listb = listb->next;
			}
		}
		else
			write (1, "numero invalido e/ou repetido\n", 30); 
	}
	else
		write (1, "insira um numero\n", 16);
	return (0);
}
