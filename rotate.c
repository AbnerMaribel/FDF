/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:54:50 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/12 10:59:04 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void rotate(float *x, float *y, double angle)
{
    *x = *x * cos(angle) - *y * sin(angle);
	*y = *x * sin(angle) + *y * cos(angle);
}