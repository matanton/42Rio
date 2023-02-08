/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:38:53 by matanton          #+#    #+#             */
/*   Updated: 2023/02/08 11:43:51 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1080, 1020, "fdf");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, 1050, 1000);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
			&data->img.line_len, &data->img.endian);
	return (0);
}

void	f_image(t_data data)
{
	mlx_put_image_to_window (data.mlx_ptr, data.win_ptr, \
			data.img.mlx_img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_hook (data.win_ptr, 17, 0, &handle_x, &data);
	mlx_loop (data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	return (0);
}

int	handle_x(int sym, t_data *data)
{
	if (sym == -501868232)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	exit (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}
