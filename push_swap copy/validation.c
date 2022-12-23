/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:36:08 by matanton          #+#    #+#             */
/*   Updated: 2022/12/19 18:09:35 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeated(int argc, char **data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc - 2)
	{
		while (i + j <= argc - 2)
		{
			j++;
			if (ft_strncmp(data[i], data[i + j], 10) == 0)
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	is_number(int argc, char **data)
{
	int	i;
	int	j;
	int	s;

	i = 1;
	while (i < argc)
	{
		s = ft_strlen(data[i]);
		if (((data[i][0] == '+' || data[i][0] == '-') && data[i][1]) \
				|| ft_isdigit(data[i][0]))
		{
			j = 1;
			while (j < s)
			{
				if (ft_isdigit(data[i][j]))
					j++;
				else
					return (0);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

long signed int	ft_psatoi(char *str)
{
	int			i;
	int			sign;
	long int	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (str[i] - '0') + (r * 10);
		i++;
	}
	return (r * sign);
}

int	is_long(int argc, char **data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_psatoi(data[i]) <= 2147483647 \
				&& ft_psatoi(data[i]) >= -2147483648)
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_sorted(t_list **list)
{
	while ((*list)->next != NULL)
	{
		if ((*list)->elem > (*list)->next->elem)
			return (0);
		else
			*list = (*list)->next;
	}
	return (1);
}
