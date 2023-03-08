/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:31:13 by matanton          #+#    #+#             */
/*   Updated: 2023/03/08 19:43:33 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while(philo->general->is_dead != 1)
	{
		if(philo->status == 0 && philo->general->is_dead == 0)
		{
			print_status(philo, 0);
			philo->status = 1;
		}
		if(philo->general->is_limit_eat && philo->times_eaten >= \
				philo->general->times_to_eat)
			return (NULL);
		if(philo->status == 1 && philo->general->is_dead == 0)
			eating(philo);
		if(philo->status == 2 && philo->general->is_dead == 0)
		{
			print_status(philo, 2);
			ft_sleep(philo, philo->general->time_sleep);
			philo->status = 0;
		}
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->general->forks[philo->l_fork]);
	print_status(philo, 3);
	if(philo->general->n_philo == 1)
	{
		ft_sleep(philo, philo->general->time_die);
		pthread_mutex_unlock(&philo->general->forks[philo->l_fork]);
		return;
	}
	if(philo->general->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->general->forks[philo->l_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->general->forks[philo->r_fork]);
	print_status(philo, 3);
	if(philo->general->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->general->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->general->forks[philo->r_fork]);
		return;
	}
	philo->last_eaten = time_ms();
	print_status(philo, 1);
	ft_sleep(philo, philo->general->time_eat);
	(philo->times_eaten)++;
	pthread_mutex_unlock(&philo->general->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->general->forks[philo->r_fork]);
	philo->status = 2;
}

void	*dinner_check(void *param)
{
	t_philo	*philo;
	int		i;
	pthread_mutex_t	hold_print;

	philo = (t_philo *)param;
	i = 0;
	pthread_mutex_init(&hold_print, NULL);
	pthread_mutex_lock(&hold_print);
	while(philo->general->is_dead != 1)
	{
		if((time_ms() - philo->general->initial_time - \
					philo[i].last_eaten) > (philo[i].general->time_die))
		{
			printf("%d %d is dead\n",
				   (int)(time_ms() - philo->general->initial_time), philo->philo_id);
			philo->general->is_dead = 1;
		}
		if(check_all(philo))
			philo->general->is_dead = 1;
		i = (i + 1) % philo->general->n_philo;
	}
	pthread_mutex_unlock(&hold_print);
	pthread_mutex_destroy(&hold_print);
	return (NULL);
}

int	check_all(t_philo *philo)
{
	int	i;

	i = 0;
	if(!philo->general->is_limit_eat)
		return (0);
	while(i < philo->general->n_philo)
	{
		if(philo[i].times_eaten < philo->general->times_to_eat)
			return (0);


		else
			i++;
	}
	return (1);
}


