/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:28:22 by amaribel          #+#    #+#             */
/*   Updated: 2022/02/02 00:15:41 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int		is_key(int key)
// {
// 	return (key == 69 || key == 78 || key == 91 || key == 84 ||\
// 	key == 125 || key == 126 || key == 123 || key == 124);
// }

// void	do_key(int key, t_map **map)
// {
// 	if (key == 69)
// 		(*map)->scale += 3;
// 	if (key == 78)
// 		(*map)->scale -= 3;
// 	if (key == 91)
// 		(*map)->z_scale += 1;
// 	if (key == 84)
// 		(*map)->z_scale -= 1;
// 	if (key == 125)
// 		(*map)->shift_y -= 10;
// 	if (key == 126)
// 		(*map)->shift_y += 10;
// 	if (key == 123)
// 		(*map)->shift_x -= 10;
// 	if (key == 124)
// 		(*map)->shift_x += 10;
// }

// int		keys(int key, t_map **map)
// {
// 	if (is_key(key))
// 	{
// 		mlx_clear_window((*map)->mlx_ptr, (*map)->win_ptr);
// 		do_key(key, map);
// 		//print_menu(*map);
// 		//draw(map);
// 	}
// 	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
// 		//new_window(key, map);
// 	if (key == '5')
// 	{
// 		mlx_destroy_window((*map)->mlx_ptr, (*map)->win_ptr);
// 		free(map);
// 		exit(0);
// 	}
// 	return (0);
// }