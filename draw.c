/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:38:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/08 21:22:02 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->arr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	set_color(t_point point1, t_point point2, fdf *data)
{
	if (point1.z == 0 && point2.z == 0)
	{
		data->color = 0xa2c7fe;
		data->color1 = 0xa2c7fe;
	}
	else if (point1.z != 0 && point2.z != 0 && (point2.z - point1.z) == 0)
	{
		data->color = 0xc016f0;
		data->color1 = 0xc016f0;
	}
	else if (point1.z == 0 || point2.z == 0)
	{
		data->color = 0xffd1ff;
		data->color1 = 0x1b1ebf;
	}
}

void	bresenham(t_point point1, t_point point2, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	i;

	// point1.z = data->matrix[(int)(point1.y)][(int)(point1.x)];
	// point2.z = data->matrix[(int)point2.y][(int)point2.x];
	zoom(&point1, &point2, data);
	set_color(point1, point2, data);
	isometric(&point1.x, &point1.y, point1.z);
	isometric(&point2.x, &point2.y, point2.z);
	//window_position(&point1, &point2);
	x_step = point2.x - point1.x;
	y_step = point2.y - point1.y;
	max = ft_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	i = 0;
	while (i < max)
	{
		my_mlx_pixel_put(data, point1.x + x_step * i, point1.y + y_step * i,
			get_gradient(data->color, data->color1, max, i));
		i++;
	}
}

void	draw(fdf *data, t_point **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j < data->width - 1)
				bresenham(matrix[i][j], matrix[i][j + 1], data);
			if (i < data->height - 1)
				bresenham(matrix[i][j], matrix[i + 1][j], data);
			j++;
		}
		i++;
	}
}
