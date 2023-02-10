/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:58 by matanton          #+#    #+#             */
/*   Updated: 2023/02/10 19:08:04 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**map(int fd, t_data data)
{
	char	*line;
	char	**string;
	int		**map;
	int		l;
	int		c;

	l = 0;
	map = malloc((sizeof(int *) * data.y) + 1);
	if (!map)
		return (NULL);
	while (l < data.y)
	{
		c = 0;
		map[l] = malloc(sizeof(int) * data.x);
		line = get_next_line(fd);
		string = ft_split (line, 32);
		while (c < data.x)
		{
			map[l][c] = ft_atoi(string[c]);
			c++;
		}
		l++;
	}
	map[l + 1] = NULL;
	return (map);
}

t_iso	*get_screen(int **array, t_data data)
{
	t_iso	*map;
	int		put_x;
	int		put_y;
	int		i;

	put_y = 0;
	i = 0;
	map = malloc(sizeof(t_iso *) * data.x * data.y);
	if (!map)
		return (NULL);
	while (put_y < data.y)
	{
		put_x = 0;
		while (put_x < data.x)
		{
			map[i].sx = round (((put_x * cos(0.3)) + (put_y * cos(2.3944)) \
						+ (array[put_y][put_x] * cos(-1.7944))) * 10);
			map[i].sy = round (((put_x * sin(0.3)) + (put_y * sin(2.3944)) \
						+ (array[put_y][put_x] * sin(-1.7944))) * 10);
			put_x++;
			i++;
		}
		put_y++;
	}
	return (map);
}

static void	get_min(t_iso *screen, t_data *data)
{
	int	minx;
	int	miny;
	int	i;

	i = -1;
	minx = screen[0].sx;
	miny = screen[0].sy;
	while (i++ < (*data).x * (*data).y - 1)
	{
		if (minx > screen[i].sx)
			minx = screen[i].sx;
		if (miny > screen[i].sy)
			miny = screen[i].sy;
	}
	(*data).minx = minx;
	(*data).miny = miny;
}

void	correct_values(t_iso *screen, t_data data)
{
	int	i;

	i = -1;
	get_min(screen, &data);
	if (data.minx < 0)
	{
		data.minx = data.minx * -1;
		while (i++ < data.x * data.y - 1)
			screen[i].sx += data.minx;
	}
	i = -1;
	if (data.miny < 0)
	{
		data.miny = data.miny * -1;
		while (i++ < data.x * data.y - 1)
			screen[i].sy += data.miny;
	}
}

void	fill(t_iso *screen, t_data data)
{
	int	x;

	x = 0;
	while (x < data.x * data.y - 1)
	{
		if ((x + 1) % data.x != 0)
			draw_line (screen[x], screen[x + 1], &data);
		if (x < (data.x * data.y) - data.x)
			draw_line (screen[x], screen[x + data.x], &data);
		x++;
	}
}
