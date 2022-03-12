/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:19:05 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/12 11:10:01 by amaribel         ###   ########.fr       */
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

#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct
{
	float	x;
	float	y;
	float 	z;
	int		color;
}	point;

typedef struct
{
	int width;
	int height;
	point **matrix;
	int zoom;
	void *mlx_ptr;
	void *win_ptr;
	void *image;
	char *arr;
	int bpp;
	int line_length;
	int endian;
	int shift_x;
	int shift_y;
	int flag;
	double angle;
}	fdf;



//main.c
int	end(void *data);
int	keys(int key, fdf *data);

//reading_file.c
int	get_height(char *filename);
int	ft_counter(char *s, char c);
int	get_width(char *filename);
void	fill_matrix(point *matrix_line, int line_num, char *line, fdf *data);
void	read_file(char *filename, fdf *data);

//draw.c
void	my_mlx_pixel_put(fdf *data, int x, int y, int color);
void	isometric(float *x, float *y, float z);
void	set_color(point point1, point point2, fdf *data);
void	bresenham(point point1, point point2, fdf *data);
void	draw(fdf *data, point **matrix);

//gradient.c
int	create_rgb(int red, int green, int blue);
int	spectr(int color, int mask, int shift);
int	get_gradient(int start, int end, size_t range, size_t point);

//ft_free.c
void	ft_free_fdf(fdf *data);
void	ft_free_char(char **words);

//utils.c
int	ft_max(float a, float b);
float	mod(float i);
void	zoom(point *point1, point *point2, fdf *data);
void	window_position(point *point1, point *point2, fdf *data);
int	ft_atoi1(char *str);

//rotate.c
void rotate(float *x, float *y, double angle);

#endif