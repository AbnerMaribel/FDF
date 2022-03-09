/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:37:08 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/08 21:20:48 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	zoom(t_point *point1, t_point *point2, fdf *data)
{
	point1->x *= data->zoom;
	point1->y *= data->zoom;
	point1->z *= data->zoom;
	point2->x *= data->zoom;
	point2->y *= data->zoom;
	point2->z *= data->zoom;
}

void	window_position(t_point *point1, t_point *point2)
{
	point1->x += 400;
	point1->y += 400;
	point2->x += 400;
	point2->y += 400;
}
