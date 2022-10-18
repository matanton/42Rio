/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:12 by matanton          #+#    #+#             */
/*   Updated: 2022/10/12 14:06:25 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	client(int pid, unsigned char *message)
{
	int	i;
	int	move;

	move = 0;
	i = 0;
	while (message[i])
	{
		while (move < 8)
		{
			if (message[i] & 128 >> move)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
			move++;
		}
		i++;
		move = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("client: invalid arguments");
	}
	pid = ft_atoi(argv[1]);
	client(pid, (unsigned char *)argv[2]);
	return (0);
}
