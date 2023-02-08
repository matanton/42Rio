/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:58 by matanton          #+#    #+#             */
/*   Updated: 2023/02/08 11:52:33 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**map(int fd, t_data data)
{
	char	*line;
	char	**string;
	int		**map;
	int		l;
	int 	c;

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
	map[l+1] = NULL;
	return (map);
}

t_iso	*get_screen(int **array, t_data data)
{
	// 	ang = 150
	// 	rot = 270
	//  a - 120 = 30 (z)
	t_iso	*map;
	double	cos_ang = cos(0.3);
	double	sen_ang = sin(0.3);
	double	cos_rot = cos(2.3944);
	double	sen_rot = sin(2.3944);
	double	cos_a = cos(-1.7944);
	double	sen_a = sin(-1.7944);
	int 	put_x = 0;
	int		put_y = 0;
	double		screen_x = 0;
	double		screen_y = 0;
	int			i = 0;
	//int		screen_xd = 0;
	//int		screen_yd = 0;


	map = malloc(sizeof(t_iso *) * data.x * data.y);
	if (!map)
		return (NULL);
	while (put_y < data.y)
	{
		put_x = 0;
		while (put_x < data.x)
		{
			//screen_x = put_x;
			//screen_y = put_y;
			screen_x = (put_x * cos_ang) + (put_y * cos_rot) + (array[put_y][put_x] * cos_a);
			screen_y = (put_x * sen_ang) + (put_y * sen_rot) + (array[put_y][put_x] * sen_a);
			map[i].sx = round(screen_x * 2);
			map[i].sy = round(screen_y * 2);
			put_x++;
			i++;
		}
		put_y++;
	}
	return (map);
}

void	correct_values(t_iso *screen, t_data data)
{
	int	i = -1;
	int minx = screen[0].sx;
	int miny = screen[0].sy;
	while (i++ < data.x * data.y - 1)
	{
		if (minx > screen[i].sx)
			minx = screen[i].sx;
		if (miny > screen[i].sy)
			miny = screen[i].sy;
	}
	i = -1;
	if (minx < 0)
	{
		minx = minx * -1;
		while (i++ < data.x * data.y - 1)
			screen[i].sx += minx;
	}
	i = -1;
	if (miny < 0)
	{
		miny = miny * -1;
		while (i++ < data.x * data.y - 1)
			screen[i].sy += miny;
	}
	printf("\n");
	i = 0;
	while (i++ < data.x * data.y - 1)
		printf("x: %i, y: %i", screen[i].sx, screen[i].sy);
}

void	fill(t_iso *screen, t_data data)
{
	int	x;
	//int	y;

	x = 0;
	//y = 0;
	while (x < data.x * data.y - 1)
	{
		if ((x + 1) % data.x != 0)
			draw_line (screen[x], screen[x + 1], &data);
		if (x < (data.x * data.y) - data.x)
			draw_line (screen[x], screen[x + data.x], &data);
		x++;
	}
}
