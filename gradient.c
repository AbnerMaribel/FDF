/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:58:56 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/08 12:48:54 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	spectr(int color, int mask, int shift)
{
	return ((color & mask) >> shift);
}

int	get_gradient(int start, int end, size_t range, size_t point)
{
	int	res;
	int	r;
	int	g;
	int	b;

	if (point > range)
		point = range;
	r = spectr(end, R_MASK, R_SHIFT) - spectr(start, R_MASK, R_SHIFT);
	g = spectr(end, G_MASK, G_SHIFT) - spectr(start, G_MASK, G_SHIFT);
	b = spectr(end, B_MASK, B_SHIFT) - spectr(start, B_MASK, B_SHIFT);
	res = create_rgb((int)(spectr(start, R_MASK, R_SHIFT)
				+ (double)r / range * point),
			(int)(spectr(start, G_MASK, G_SHIFT) + (double)g / range * point),
			(int)(spectr(start, B_MASK, B_SHIFT) + (double)b / range * point));
	return (res);
}
