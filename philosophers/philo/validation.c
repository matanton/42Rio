/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:59:01 by matanton          #+#    #+#             */
/*   Updated: 2023/03/08 19:29:46 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(t_general *general, int argc, char **argv)
{
	int			i;
	long int	n;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			n = ft_latoi(argv[i]);
			if (!is_num(argv[i]) || (n > 2147483647) || (n < -2147483648))
				return (0);
			i++;
		}
		if (arg_philo(general, argc, argv) == 1)
			return (1);
	}
	else
		printf("./philo number_of_philosophers time_to_die time_to_eat \
				time_to_sleep [number_of_times_each_philosopher_must_eat] \
				\n");
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_num(char *string)
{
	int	j;
	int	s;

	j = 1;
	s = ft_strlen(string);
	if (((string[0] == '+' || string[0] == '-') && string[1]) \
			|| ft_isdigit(string[0]))
	{
		while (string[j] != '\0')
		{
			if (ft_isdigit(string[j]))
				j++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

long signed int	ft_latoi(char *str)
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
