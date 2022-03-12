/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:37:08 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/12 09:30:29 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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

void	zoom(point *point1, point *point2, fdf *data)
{
	point1->x *= data->zoom;
	point1->y *= data->zoom;
	point1->z *= data->zoom;
	point2->x *= data->zoom;
	point2->y *= data->zoom;
	point2->z *= data->zoom;
}

void	window_position(point *point1, point *point2, fdf *data)
{
	point1->x += data->shift_x;
	point1->y += data->shift_y;
	point2->x += data->shift_x;
	point2->y += data->shift_y;
}

int	ft_atoi1(char *str)
{
	int	res;
	int	len;
	int num;
	int	i;

	i = 0;
	res = 0;
    len = ft_strlen(str);
	while(i < len)
    {
        if (str[i] >= 'a' && str[i] <= 'f')
			num = str[i] - 87;
		if (str[i] >= 'A' && str[i] <= 'F')
			num = str[i] - 55;
		if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		res = res + num * pow(16, (len - i - 1));
		i++;
    }
	return (res);
}