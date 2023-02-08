/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:09 by matanton          #+#    #+#             */
/*   Updated: 2023/02/08 11:56:06 by matanton         ###   ########.fr       */
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

	data->x = 0;
	line = "42";
	line = get_next_line(fd);
	data->y = 1;
	string = ft_split(line, 32);
	while (string[data->x] != NULL)
		(data->x)++;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			(data->y)++;
		free(line);
	}
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
	int dx = (p1.sx - p0.sx);
    int dy = (p1.sy - p0.sy);
    int yi = 1;
	int x = round(p0.sx);
    int d;
	int	y;

	if (dy < 0)
	{
        yi = -1;
        dy = dy * -1;
	}
	d = (2 * dy) - dx;
	y = round(p0.sy);
	while (x < p1.sx)
    {
		draw_pixel(data, x, y);
        if (d > 0)
		{
			y = y + yi;
            d = d + (2 * (dy - dx));
		}
		else
            d = d + 2 * dy;
		x++;
	}
}

void	plotline_high(t_iso p0, t_iso p1, t_data *data)
{
	int dx = (p1.sx - p0.sx);
    int dy = (p1.sy - p0.sy);
    int xi = 1;
	int y = round(p0.sy);
    int d;
	int	x;

	if (dx < 0)
	{
        xi = -1;
        dx = dx * -1;
	}
	else
	d = (2 * dx) - dy;
	x = round(p0.sx);
	while (y < p1.sy)
    {
		draw_pixel(data, x, y);
        if (d > 0)
		{
			x = x + xi;
            d = d + (2 * (dx - dy));
		}
		else
            d = d + 2 * dx;
		y++;
	}
}
