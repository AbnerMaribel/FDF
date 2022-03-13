/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:56:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:18:28 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate(t_point *point, t_fdf *data)
{
	point->x = point->x * cos(data->angle) - point->y * sin(data->angle);
	point->y = point->x * sin(data->angle) + point->y * cos(data->angle);
}

void	iso(t_point *point1, t_point *point2)
{
	isometric(point1);
	isometric(point2);
}

void	rot(t_point *point1, t_point *point2, t_fdf *data)
{
	isometric(point1);
	isometric(point2);
	rotate(point1, data);
	rotate(point2, data);
}
