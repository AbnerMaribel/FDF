/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:02:22 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/08 18:28:47 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_fdf(fdf *data)
{
	int	height;
	int	i;

	height = data->height;
	i = 0;
	while (i < height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data->arr);
	free(data);
}

void	ft_free_char(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
