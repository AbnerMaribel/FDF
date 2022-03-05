/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:30:42 by amaribel          #+#    #+#             */
/*   Updated: 2021/10/22 18:28:41 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	counter;

	counter = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;

	counter = ft_counter(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[counter--] = '\0';
	while (n / 10 > 0)
	{
		str[counter--] = (n % 10) + '0';
		n = n / 10;
	}
	str[counter] = (n % 10) + '0';
	return (str);
}
