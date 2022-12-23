/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:34:19 by matanton          #+#    #+#             */
/*   Updated: 2022/12/23 15:21:39 by matanton         ###   ########.fr       */
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
			if (is_sorted(&list))
				write (1, "is sorted\n", 10);
			array = ft_sort(argc, data);
			int j = 0;
			while (array[j])
			{
				printf("p.%i: %i\n", j, array[j]);
				j++;
			}
			put_index(array, &list, argc - 1);
			while (list != NULL)
			{
				printf("index= %i\t", list->index);
				printf("elem= %i\n", list->elem);
				list = list->next;
			}
		}
		else
			write (1, "numero invalido e/ou repetido\n", 30); 
	}
	else
		write (1, "insira um numero\n", 16);
	return (0);
}
