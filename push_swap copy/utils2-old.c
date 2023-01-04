/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:01 by matanton          #+#    #+#             */
/*   Updated: 2023/01/02 19:38:34 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_sort(int argc, char **data)
{
	int *list;
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
		
	list = malloc(sizeof(argc - 1));
	while (j < argc)
	{
		list[i] = ft_atoi(data[j]);
		i++;
		j++;
	}

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
	i = 0;
	return (list);
}

void	put_index(int *array, t_list **list, int size_array)
{
	int	i;
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
				printf("list: %i; i: %i\n", (*list)->elem, i);
				(*list)->index = i;
				i++;
				break ;
			}
			*list = (*list)->next;
			if ((*list)->elem == 8)
				break ;
		//	i++;
			//printf("2 list: %i; i: %i\n", (*list)->elem, i);
		}
	}
	write(1, "m", 1);	
}

/* comecei a fazer com a thatha mas nao terminei
void	ft_sortbig(t_list **list)
{
	int	i;
	int	bit;
	int	size;

	i = 0;
	bit = 0;
	size = 0;

	while ((*list)->next != NULL)
		size++;
		*list = (*list)->next;
	while (!is_sorted(list))
	{
		while (i < size)
		{
			if ((*list)->index << bit & 1)
				ra
			else
				pb
*/

