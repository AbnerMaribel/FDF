/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:58:56 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/05 22:04:16 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// double percent(int min_z, int max_z, int z)
// {
//     double distance;
//     double delta;

//     distance = max_z - min_z;
//     delta = z - min_z;
//     if (distance == 0)
//         return (1.0);
//     else
//         return (delta / distance);
// }

// int gradient(double point)
// {
//     if (point)
//         return(YELLOW);
//     else if (point)
//         return(GREEN);
//     else if (point)
//         return(BLUE);
//     else if (point)
//         return(DARK_BLUE);
//     else if (point)
//         return(PINK);
//     else
//         return(RED);
// }

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int get_spectr(int color, int mask, int shift)
{
	return ((color & mask) >> shift);
}

int		get_gradient(int start, int end, size_t range, size_t point)
{
	int	result;
	int	red;
	int	green;
	int	blue;

	if (point > range)
		point = range;
	red = get_spectr(end, R_MASK, R_SHIFT) - get_spectr(start, R_MASK, R_SHIFT);
	green = get_spectr(end, G_MASK, G_SHIFT) - get_spectr(start, G_MASK, G_SHIFT);
	blue = get_spectr(end, B_MASK, B_SHIFT) - get_spectr(start, B_MASK, B_SHIFT);
	result	= create_rgb((int)(get_spectr(start, R_MASK, R_SHIFT) + (double)red / range * point), (int)(get_spectr(start, G_MASK, G_SHIFT) + (double)green / range * point), (int)(get_spectr(start, B_MASK, B_SHIFT) + (double)blue / range * point));
	return (result);
}
