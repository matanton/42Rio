/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:29:24 by matanton          #+#    #+#             */
/*   Updated: 2023/03/06 11:10:20 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*func(void *arg)
{
	pthread_detach(pthread_self());
	printf("Inside the thread\n");
	pthread_exit(NULL);
}

void fun()
{
	pthread_t	ptid;

	pthread_create(&ptid, NULL, &func, NULL);
	printf("A thread ainda não acabou\n");
	if (pthread_equal(ptid, pthread_self()))
		printf("Thread são iguais\n");
	else
		printf("Threads NÃO são iguais\n");
	pthread_join(ptid, NULL);
	printf("A thread acabou\n");
	pthread_exit(NULL);
}

t_philo	*parse_data(t_general *general)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * general->n_philo);
	general->forks = malloc(sizeof(pthread_mutex_t) * general->n_philo);
	while (i < general->n_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % general->n_philo;
		philo[i].last_eaten = 0;
		philo[i].times_eaten = 0;
		philo[i].general = general;
		pthread_mutex_init(&general->forks[i], NULL);
		//printf("garfo esquerdo: %d\n", general.philo[i].l_fork);
		//printf("filosofo: %d\n", general.philo[i].philo_id);
		//printf("garfo direito: %d\n", general.philo[i].r_fork);
		i++;
	}
	return (philo);
}

// 0 = pensando;
// 1 = comendo;
// 2 = dormindo;

void	*dinner(void *arg)
{
	t_philo	*philo;
   
	philo = (t_philo *)arg;
	printf("%d is on", philo->philo_id);
	/*
	while (1) //colocar a variavel que verifica se esta morto;
	{
		if(philo->status == 0)
		{
			printf("%d is thinking\n", philo->philo_id);
			philo->status = 1;
		}
		// antes de comer verificar se o filosofo ta vivo;
		if(philo->status == 1)
		{
			pthread_mutex_lock(&philo->general->forks[philo->l_fork]);	
			printf("%d has taken a fork\n", philo->philo_id);
			//verificar se ele esta morto;
			//se estiver morto solta o garfo - mutex unlock;
			pthread_mutex_lock(&philo->general->forks[philo->r_fork]);
			printf("%d has taken a fork\n", philo->philo_id);
			//verificar se ele esta morto;
			//se estiver morto, solta ambos os garfos - mutex unlock;
			//colocar o tempo de agora como o tempo last_eaten;
			(philo->times_eaten)++;
			printf("%d has eaten\n", philo->philo_id);
			//colocar ft_usleep;
			pthread_mutex_unlock(&philo->general->forks[philo->l_fork]);	
			pthread_mutex_unlock(&philo->general->forks[philo->r_fork]);
			//verificar se so ha somente um filosofo (pode ser feito na main);
			philo->status = 2;
		}
		if(philo->status == 2)
		{
			printf("%d is sleeping\n", philo->philo_id);
			//colocar ft_usleep;
			philo=>status = 0;
		}
	}*/
	return NULL;
}

/*void	ft_timestamp();
{}


void	ft_usleep(t_general general, int status)
{

	if (status == 1)
}*/

void	create_philo(t_philo *philo)
{
	int			i;
	pthread_t	*pd;

	i = 0;
	pd = malloc(sizeof(pthread_t) * philo[0].general->n_philo);
	while (i < philo[0].general->n_philo)
	{
		if(pthread_create(&pd[i], NULL, &dinner, (void*)(philo + i)))
			exit(1);
		i++;
	}
	i = 0;
	while (i < philo[0].general->n_philo)
	{
		if(pthread_join(pd[i], NULL))
			exit(1);
		i++;
	}
}

int	arg_philo(t_general *general, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		general->n_philo = ft_latoi(argv[1]);
		general->time_die = ft_latoi(argv[2]);
		general->time_eat = ft_latoi(argv[3]);
		general->time_sleep = ft_latoi(argv[4]);
		if (argc == 6)
		{
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

int	arg_check(t_general *general, int argc, char **argv)
{
	int			i;
	long int	n;

	i = 0;
	printf("entrou no arg_check");
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			printf("entrou no while");
			n = ft_latoi(argv[i]);
			if (!is_num(argv[i]) || (n > 2147483647) || (n > -2147483648))
				return (1);
		}
		if(arg_philo(general, argc, argv))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_general	general;

	printf("não é possíve");
	if(!arg_check(&general, argc, argv))
		return (1);
	printf("arg check ok");
	philo = parse_data(&general);
	printf("parse data ok");
	create_philo(philo);

	int i = 0;
	while (i < general.n_philo)
	{
   		printf("garfo esquerdo: %d\n", philo[i].l_fork);
		printf("filosofo: %d\n", philo[i].philo_id);
		printf("garfo direito: %d\n", philo[i].r_fork);
		i++;
	}/*
	if (philo_valid(&general, argc, argv) == 0)
		printf("philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	printf("numero philo: %i\ntime_to_die: %i\ntime_to_eat: %i\ntime_to_sleep: %i\ntimes_to_eat: %i\n", general.n_philo, general.time_die, general.time_eat, general.time_sleep, general.times_to_eat);
*/
}
