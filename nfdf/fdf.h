/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:02:04 by matanton          #+#    #+#             */
/*   Updated: 2023/02/10 18:56:09 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		minx;
	int		miny;
	t_img	img;
}	t_data;

typedef struct s_iso
{
	int	sx;
	int	sy;
}	t_iso;

int		init_mlx(t_data *data);
void	f_image(t_data data);
//void	ft_put_line(int x, int y, int size_line);
int		handle_no_event(void *data);
int		handle_x(int sym, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	get_x_y(int fd, t_data *data);
int		**map(int fd, t_data data);
void	correct_values(t_iso *screen, t_data data);
t_iso	*get_screen(int **array, t_data data);
void	draw_pixel(t_data *data, int x, int y);
//void	line_points(int *array, int x, int y, int size_line);
void	draw_line(t_iso p0, t_iso p1, t_data *data);
void	plotline_low(t_iso p0, t_iso p1, t_data *data);
void	plotline_high(t_iso p0, t_iso p1, t_data *data);
void	fill(t_iso *screen, t_data data);

#endif
