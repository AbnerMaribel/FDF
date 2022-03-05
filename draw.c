/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:38:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/05 20:39:29 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char *dst;
	
	dst = malloc(sizeof(char) * (data->width * data->height + 1));
	dst = data->arr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

int ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data) 
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom; 
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	if (z > 0 || z1 > 0)
		data->color = 0x9c40b3;
	else if (z < 0 || z1 < 0)
		data->color = 0x3270b3;
	else
		data->color = 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += 400;
	y += 200;
	x1 += 400;
	y1 += 200;
	x_step = x1 - x; 
	y_step = y1 - y; 
	max = ft_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
