/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:38:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:19:24 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 1000 || x <= 0 || y <= 0 || y >= 1000)
		return ;
	dst = data->arr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

void	isometric(t_point *point)
{
	point->x = (point->x - point->y) * cos(0.523599);
	point->y = (point->x + point->y) * sin(0.523599) - point->z;
}

void	bresenham(t_point point1, t_point point2, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		i;

	zoom(&point1, &point2, data);
	if (data->flag == 1)
		iso(&point1, &point2);
	if (data->flag == 2)
		rot(&point1, &point2, data);
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

void	draw(t_fdf *data, t_point **matrix)
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
