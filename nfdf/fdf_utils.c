/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:09 by matanton          #+#    #+#             */
/*   Updated: 2023/02/10 20:30:41 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_data *data, int x, int y)
{
	char	*pixel;

	if (x < 1020 && y < 969)
	{
		pixel = data->img.addr + (y * data->img.line_len) + (x * 4);
		*(unsigned int *)pixel = 0xFFFFFF;
	}
}

void	get_x_y(int fd, t_data *data)
{
	char	*line;
	char	**string;
	int		i;

	i = 0;
	data->x = 0;
	line = get_next_line(fd);
	data->y = 1;
	string = ft_split(line, 32);
	free (line);
	while (string[data->x] != NULL)
		(data->x)++;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			(data->y)++;
		free(line);
	}
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free (string);
}

void	draw_line(t_iso p0, t_iso p1, t_data *data)
{
	if (abs(p1.sy - p0.sy) < abs(p1.sx - p0.sx))
	{
		if (p0.sx > p1.sx)
			plotline_low(p1, p0, data);
		else
			plotline_low(p0, p1, data);
	}
	else
	{
		if (p0.sy > p1.sy)
			plotline_high(p1, p0, data);
		else
			plotline_high(p0, p1, data);
	}
}

void	plotline_low(t_iso p0, t_iso p1, t_data *data)
{
	int	yi;
	int	x;
	int	d;
	int	y;

	yi = 1;
	if ((p1.sy - p0.sy) < 0)
		yi = -1;
	d = (2 * (p1.sy - p0.sy) * yi) - (p1.sx - p0.sx);
	x = p0.sx;
	y = p0.sy;
	while (x < p1.sx)
	{
		draw_pixel(data, x, y);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (((p1.sy - p0.sy) * yi) - (p1.sx - p0.sx)));
		}
		else
			d = d + (2 * (p1.sy - p0.sy) * yi);
		x++;
	}
}

void	plotline_high(t_iso p0, t_iso p1, t_data *data)
{
	int	xi;
	int	y;
	int	d;
	int	x;

	xi = 1;
	if ((p1.sx - p0.sx) < 0)
		xi = -1;
	d = (2 * (p1.sx - p0.sx) * xi) - (p1.sy - p0.sy);
	x = p0.sx;
	y = p0.sy;
	while (y < p1.sy)
	{
		draw_pixel(data, x, y);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (((p1.sx - p0.sx) * xi) - (p1.sy - p0.sy)));
		}
		else
			d = d + (2 * (p1.sx - p0.sx) * xi);
		y++;
	}
}
