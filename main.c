/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:08:38 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/08 21:22:06 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end(void *data)
{
	data = (fdf *)data;
	ft_free_fdf(data);
	exit(0);
}

int	keys(int key, fdf *data)
{
	if (key == 53)
	{
		ft_free_fdf(data);
		exit(0);
	}	
	return (0);
}

int	main(int argc, char **argv)
{
	fdf	*data;
	t_point **matrix;

	if (argc != 2)
		return (0);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		exit(1);
	read_file(argv[1], data);
	matrix = coord_matrix(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->image = mlx_new_image (data->mlx_ptr, 1000, 1000);
	data->arr = mlx_get_data_addr(data->image, &data->bpp, &data->line_length,
			&data->endian);
	//data->zoom = 1;
	draw(data, matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, end, (void *)data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
