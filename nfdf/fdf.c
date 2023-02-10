/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:30 by matanton          #+#    #+#             */
/*   Updated: 2023/02/10 18:55:28 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_iso	*screen;
	int		**array;
	int		fd;

	if (argc > 1 && argc <= 3)
	{
		fd = open(argv[1], 0);
		if (fd < 1)
			return (2);
		get_x_y(fd, &data);
		close(fd);
		fd = open(argv[1], 0);
		init_mlx(&data);
		array = map(fd, data);
		screen = get_screen(array, data);
		correct_values(screen, data);
		fill(screen, data);
		f_image(data);
	}
	return (0);
}
