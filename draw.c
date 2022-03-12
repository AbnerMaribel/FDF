/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:38:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/12 11:21:22 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 1000 || x <= 0 || y <= 0 || y >= 1000)
		return ;
	dst = data->arr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void	bresenham(point point1, point point2, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int	i;

	zoom(&point1, &point2, data);
	if (data->flag == 1) // изометрическая проекция
	{
		isometric(&point1.x, &point1.y, point1.z);
		isometric(&point2.x, &point2.y, point2.z);
	}
	if (data->flag == 2) // вращение
	{
		isometric(&point1.x, &point1.y, point1.z);
		isometric(&point2.x, &point2.y, point2.z);
		rotate(&point1.x, &point1.y, data->angle);
		rotate(&point2.x, &point2.y, data->angle);
	}
	window_position(&point1, &point2, data);
	x_step = point2.x - point1.x;
	y_step = point2.y - point1.y;
	max = ft_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	i = 0;
	while (i < max)
	{
		my_mlx_pixel_put(data, point1.x + x_step * i, point1.y + y_step * i,
			get_gradient(point1.color, point2.color, max, i));
		i++;
	}
}

void	draw(fdf *data, point **matrix)
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
