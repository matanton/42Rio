/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:46:05 by matanton          #+#    #+#             */
/*   Updated: 2023/03/06 10:45:01 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_general
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_to_eat;
	pthread_mutex_t	*forks;
} t_general;

typedef	struct	s_philo
{
	pthread_t	thread;
	int			philo_id;
	int			l_fork;
	int			r_fork;
	int			last_eaten;
	int			times_eaten;
	int			status;
	t_general	*general;
	//garfo esquerdo;
	//garfo direito;
	//ultima vez que ele comeu
	//quantidade de vez que ja comeu
} t_philo;

long signed int	ft_latoi(char *str);
int	is_num(char *string);

#endif
