/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:57:49 by matanton          #+#    #+#             */
/*   Updated: 2023/03/15 16:07:25 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct	s_general
{
	int			n_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			is_limit_eat;
	int			times_to_eat;
	long int	initial_time;
	int			is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	doctor;
	pthread_mutex_t print;
} t_general;

typedef	struct	s_philo
{
	//pthread_t	thread;
	int			philo_id;
	int			l_fork;
	int			r_fork;
	long int	last_eaten;
	int			times_eaten;
	int			status;
	t_general	*general;
} t_philo;

long signed int	ft_latoi(char *str);
int			is_num(char *string);
int			arg_check(t_general *general, int argc, char **argv);
int			arg_philo(t_general *general, int argc, char **argv);
void		create_philo(t_philo *philo);
void		*dinner(void *param);
void		*dinner_check(void *param);
int			check_all(t_philo *philo);
void		eating(t_philo *philo);
t_philo		*parse_data(t_general *general);
long int	time_ms(void);
void	ft_sleep(t_philo *philo, int time);
void	print_status(t_philo *philo, int status);
void	one_philo(t_philo *philo);
void	create_mutex(t_philo philo);
void	destroy_mutex(t_philo philo);


#endif
