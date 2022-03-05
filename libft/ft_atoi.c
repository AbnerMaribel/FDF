/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:05:33 by amaribel          #+#    #+#             */
/*   Updated: 2021/10/22 23:14:56 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	result;
	int					sign;
	int					i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v')
		|| (str[i] == ' ') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i > 19 && sign == 1)
		return (-1);
	if (i > 19 && sign == -1)
		return (0);
	return (sign * result);
}
