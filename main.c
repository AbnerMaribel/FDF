/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:08:38 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:21:37 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end(void *data)
{
	data = (t_fdf *)data;
	ft_free_fdf(data);
	exit(0);
}

void	rotate_keys(int key, t_fdf *data)
{
	if (key == 116)
	{
		data->flag = 2;
		data->angle += 0.1;
	}
	if (key == 121)
	{
		data->flag = 2;
		data->angle -= 0.1;
	}
}

void	shift_keys(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
}

int	keys(int key, t_fdf *data)
{
	shift_keys(key, data);
	rotate_keys(key, data);
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 35)
		data->flag = 0;
	if (key == 34)
		data->flag = 1;
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image (data->mlx_ptr, 1350, 1350);
	data->arr = mlx_get_data_addr(data->image, &data->bpp, &data->line_length,
			&data->endian);
	draw(data, data->matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	if (key == 53)
	{
		ft_free_fdf(data);
		exit(0);
	}	
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		exit(1);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->image = mlx_new_image (data->mlx_ptr, 1000, 1000);
	data->arr = mlx_get_data_addr(data->image, &data->bpp, &data->line_length,
			&data->endian);
	data_init(data);
	draw(data, data->matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, end, (void *)data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
