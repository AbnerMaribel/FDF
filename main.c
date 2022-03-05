/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:08:38 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/05 20:42:02 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int end(void *var)
{
	exit(0);
}

int keys(int key, fdf *data)
{
	// mlx_destroy_image(data->mlx_ptr, data->image);
	// data->image = mlx_new_image (data->mlx_ptr, 900, 1000);
	// data->arr = mlx_get_data_addr(data->image, &data->bpp, &data->line_length, &data->endian);
	// draw(data);	
	// //mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x9c40b3, "Hello!\n");
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 100, 0);
	if (key == 53)
		exit(0);	
	return(0);
}

int	main(int argc, char **argv)
{
	fdf *data;
	
    if (argc != 2)
        return (0);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		exit(1);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->image = mlx_new_image (data->mlx_ptr, 1000, 1000);
	data->arr = mlx_get_data_addr(data->image, &data->bpp, &data->line_length, &data->endian);
	data->zoom = 10;
	draw(data);
	//bresenham(1, 1, 10, 1, data);
	//mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x9c40b3, "Hello!\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, end, NULL);
	mlx_loop(data->mlx_ptr);
	//ft_free_fdf(data);
	return (0);
}