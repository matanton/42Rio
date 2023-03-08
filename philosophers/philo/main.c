/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:59:36 by matanton          #+#    #+#             */
/*   Updated: 2023/03/08 13:42:39 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_general	general;

	if(!arg_check(&general, argc, argv))
		return (1);
	philo = parse_data(&general);
	create_philo(philo);
	
	//pthread_mutex_destroy(&general->forks[i], NULL);
	//printf("numero philo: %i\ntime_to_die: %i\ntime_to_eat: %i\ntime_to_sleep: %i\ntimes_to_eat: %i\n", general.n_philo, general.time_die, general.time_eat, general.time_sleep, general.times_to_eat);
}
