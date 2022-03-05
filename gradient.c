/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:33:41 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/02 17:18:20 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// double percent(int start, int end, int current)
// {
//     double placement;
//     double distance;
//     double prc;

//     placement = current - start;
//     distance = end - start;
//     if (distance == 0)
//         prc = 1.0;
//     prc = placement / distance;   
//     return (prc);
// }

// void    bresenham(float , t_point end, fdf *data) 
// {
// 	float x_step;
// 	float y_step;
// 	int max;
// 	int z;
// 	int z1;

// 	z = data->z_matrix[(int)start.y][(int)start.x];
// 	z1 = data->z_matrix[(int)end.y][(int)end.x];
	
// 	start.x *= data->zoom; 
// 	start.y *= data->zoom;
// 	end.x *= data->zoom;
// 	end.y *= data->zoom;

// 	if (z > 0 || z1 > 0)
// 		data->color = 0x9c40b3;
// 	else if (z < 0 || z1 < 0)
// 		data->color = 0xf50505;
// 	isometric(&start.x, &start.y, z);
// 	isometric(&end.x, &end.y, z1);

// 	start.x += 200;
// 	start.y += 200;
// 	end.x += 200;
// 	end.y += 200;
	
// 	x_step = end.x - start.x; 
// 	y_step = end.y - start.y; 
// 	max = ft_max(mod(x_step), mod(y_step));
// 	x_step /= max;
// 	y_step /= max;
// 	while((int)(start.x - end.x) || (int)(start.y - end.y))
// 	{
// 		my_mlx_pixel_put(data, start.x, start.y, get_gradient(start.color, end.color, max, max - 1));
// 		start.x += x_step;
// 		start.y += y_step;
// 	}
// }