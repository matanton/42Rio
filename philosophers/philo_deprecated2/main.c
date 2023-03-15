/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:59:36 by matanton          #+#    #+#             */
/*   Updated: 2023/03/15 16:16:19 by matanton         ###   ########.fr       */
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
//	destroy_mutex(philo[0]);
	free(philo->general->forks);
	free(philo);
}
