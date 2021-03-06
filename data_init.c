/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:07:03 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:17:57 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_fdf *data)
{
	data->zoom = 20;
	data->shift_x = 400;
	data->shift_y = 400;
	data->flag = 1;
	data->angle = 0.523599;
}
