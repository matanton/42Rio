/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:29:36 by matanton          #+#    #+#             */
/*   Updated: 2023/03/15 20:25:38 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_philo(t_general *general, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		general->n_philo = ft_latoi(argv[1]);
		general->time_die = ft_latoi(argv[2]);
		general->time_eat = ft_latoi(argv[3]);
		general->time_sleep = ft_latoi(argv[4]);
		general->is_limit_eat = 0;
		general->initial_time = 0;
		general->is_dead = 0;
		if (argc == 6)
		{
			general->is_limit_eat = 1;
			if (ft_latoi(argv[5]) <= 0)
				return (0);
			else
				general->times_to_eat = ft_latoi(argv[5]);
		}
		else
			general->times_to_eat = -1;
		if (general->n_philo <= 0 || general->time_die <= 0 || general->time_eat \
			   <= 0 || general->time_sleep <= 0)
			return (0);
		return (1);
	}
	else
		return (0);
}

void	create_philo(t_philo *philo)
{
	int			i;
	pthread_t	*pd;
	pthread_t	wait;

	i = 0;
	philo[0].general->initial_time = time_ms();
	pd = malloc(sizeof(pthread_t) * philo[0].general->n_philo);
	while (i < philo[0].general->n_philo)
	{
		if(pthread_create(&pd[i], NULL, &dinner, (void*)(philo + i)))
			exit(1);
		philo[i].philo_id = i + 1;
		i++;
	}
	pthread_create(&wait, NULL, &dinner_check, (void*)(philo));
	i = 0;
	while (i < philo[0].general->n_philo)
	{
		if(pthread_join(pd[i], NULL))
			exit(1);
		i++;
	}
	pthread_join(wait, NULL);
	free(pd);
}

t_philo	*parse_data(t_general *general)
{
	int	i;
	long int init;
	t_philo	*philo;

	i = 0;
	init = time_ms();
	philo = malloc(sizeof(t_philo) * general->n_philo);
	general->forks = malloc(sizeof(pthread_mutex_t) * general->n_philo);
	while (i < general->n_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % general->n_philo;
		philo[i].last_eaten = init;
		philo[i].times_eaten = 0;
		philo[i].general = general;
		philo[i].status = 1;
		pthread_mutex_init(&general->forks[i], NULL);
		i++;
	}
	return (philo);
}
