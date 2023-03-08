/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:33:28 by matanton          #+#    #+#             */
/*   Updated: 2023/03/08 14:28:57 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, int status)
{
	if(philo->general->is_dead == 1)
		return;
	if(status == 0)
	{
		printf("%ld %d is thinking\n", 
				(time_ms() - philo->general->initial_time), philo->philo_id);
	}
	if(status == 3)
	{
		printf("%ld %d has taken a fork\n", 
				(time_ms() - philo->general->initial_time), philo->philo_id);
	}
	if(status == 1)
	{
		printf("%ld %d is eating\n", 
				(time_ms() - philo->general->initial_time), philo->philo_id);
	}
	if(status == 2)
	{
		printf("%ld %d is sleeping\n", 
				(time_ms() - philo->general->initial_time), philo->philo_id);
	}
}

void	ft_sleep(t_philo *philo, int time)
{
	long int	init;

	init = time_ms();
	while(time_ms() - init < time)
	{
		if(philo->general->is_dead == 1)
			return;
		usleep(250);
	}
}

long int	time_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}
