/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:39 by matanton          #+#    #+#             */
/*   Updated: 2022/10/12 14:06:53 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_sigusr(int sig)
{
	static unsigned char	c;
	static int				move;

	if (sig == SIGUSR1)
		c = c | (128 >> move);
	move++;
	if (move == 8)
	{
		write(1, &c, 1);
		c = 0;
		move = 0;
	}
}

int	main(void)
{
	int	i;

	i = getpid();
	ft_printf("PID: %i \n", i);
	while (1)
	{
		signal(SIGUSR1, handler_sigusr);
		signal(SIGUSR2, handler_sigusr);
		pause();
	}
}
