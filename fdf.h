/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:19:05 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/07 12:27:19 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # define YELLOW 0xdec41d
// # define GREEN 0x85e610
// # define BLUE 0x10dbe6
// # define DARK_BLUE  0x1734c2
// # define PINK 0xd227db
// # define RED 0xe61e28

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
	int **z_matrix;
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

// typedef struct	s_point 
// {
// 	double	x;
// 	double	y;
// 	double 	z;
// 	int		color;
// }	t_point;


void	read_file(char *filename, fdf *data);
int	get_height(char *filename);
int	get_width(char *filename);
void fill_matrix(int *z_line, char *line);
// void ft_free_int(int **words, int height);
void ft_free_fdf(fdf *data);
void ft_free_char(char **words);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void draw(fdf *data);
int ft_max(float a, float b);
float mod(float i);
int keys(int key, fdf *data);
void isometric(float *x, float *y, float z);
void my_mlx_pixel_put(fdf *data, int x, int y, int color);
int		get_gradient(int start, int end, size_t range, size_t point);

#endif