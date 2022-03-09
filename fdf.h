/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:19:05 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/09 13:37:41 by amaribel         ###   ########.fr       */
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
	int width;
	int height;
	int **matrix;
	int zoom;
	int color;
	int color1;
	void *mlx_ptr;
	void *win_ptr;
	void *image;
	char *arr;
	int bpp;
	int line_length;
	int endian;
}	fdf;

typedef struct	s_point 
{
	float	x;
	float	y;
	float 	z;
	int		color;
}	t_point;


//main.c
int	end(void *data);
int	keys(int key, fdf *data);

//reading_file.c
int	get_height(char *filename);
int	ft_counter(char *s, char c);
int	get_width(char *filename);
void	fill_matrix(int *z_line, char *line);
void	read_file(char *filename, fdf *data);
t_point **coord_matrix(fdf *data);

//draw.c
void	my_mlx_pixel_put(fdf *data, int x, int y, int color);
void	isometric(float *x, float *y, float z);
void	set_color(t_point point1, t_point point2, fdf *data);
void	bresenham(t_point point1, t_point point2, fdf *data);
void	draw(fdf *data, t_point **matrix);

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
void	zoom(t_point *point1, t_point *point2, fdf *data);
void	window_position(t_point *point1, t_point *point2);

#endif