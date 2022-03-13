/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:19:05 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:40:01 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define R_MASK		0xFF0000
# define R_SHIFT	16
# define G_MASK		0x00FF00
# define G_SHIFT	8
# define B_MASK		0x0000FF
# define B_SHIFT	0

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_point	**matrix;
	int		zoom;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	char	*arr;
	int		bpp;
	int		line_length;
	int		endian;
	int		shift_x;
	int		shift_y;
	int		flag;
	double	angle;
}	t_fdf;

//main.c
int		end(void *data);
void	rotate_keys(int key, t_fdf *data);
void	shift_keys(int key, t_fdf *data);
int		keys(int key, t_fdf *data);
void	data_init(t_fdf *data);

//reading_file.c
int		get_height(char *filename);
int		ft_counter(char *s, char c);
int		get_width(char *filename);
void	fill_matrix(t_point *matrix_line, int line_nb, char *line, t_fdf *data);
void	read_file(char *filename, t_fdf *data);

//draw.c
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	isometric(t_point *point);
void	set_color(t_point point1, t_point point2, t_fdf *data);
void	bresenham(t_point point1, t_point point2, t_fdf *data);
void	draw(t_fdf *data, t_point **matrix);

//gradient.c
int		create_rgb(int red, int green, int blue);
int		spectr(int color, int mask, int shift);
int		get_gradient(int start, int end, size_t range, size_t point);

//ft_free.c
void	ft_free_fdf(t_fdf *data);
void	ft_free_char(char **words);

//utils.c
int		ft_max(float a, float b);
float	mod(float i);
void	zoom(t_point *point1, t_point *point2, t_fdf *data);
void	window_position(t_point *point1, t_point *point2, t_fdf *data);
int		ft_atoi1(char *str);

//rotate.c
void	rotate(t_point *point, t_fdf *data);
void	iso(t_point *point1, t_point *point2);
void	rot(t_point *point1, t_point *point2, t_fdf *data);

#endif