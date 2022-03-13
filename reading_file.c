/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:18:46 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/13 10:39:52 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Can't open the file\n", 20);
		exit(1);
	}
	height = 0;
	line = get_next_line(fd);
	if (line == 0)
	{
		write(1, "Empty map\n", 10);
		exit(1);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_counter(char *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

int	get_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Can't open the file\n", 20);
		exit(1);
	}
	line = get_next_line(fd);
	width = ft_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(t_point *matrix_line, int line_nb, char *line, t_fdf *data)
{
	char	**points;
	char	**coord_color;
	int		i;

	points = ft_split(line, ' ');
	i = 0;
	while (i < data->width)
	{
		coord_color = ft_split(points[i], ',');
		matrix_line[i].x = i;
		matrix_line[i].y = line_nb;
		matrix_line[i].z = ft_atoi(coord_color[0]);
		if (coord_color[1] != 0)
			matrix_line[i].color = ft_atoi1(coord_color[1] + 2);
		else if (matrix_line[i].z == 0)
			matrix_line[i].color = 0xffffff;
		else if (matrix_line[i].z > 0)
			matrix_line[i].color = 0x55155e;
		else
			matrix_line[i].color = 0x26acd1;
		i++;
		ft_free_char(coord_color);
	}
	ft_free_char(points);
}

void	read_file(char *filename, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_height(filename);
	data->width = get_width(filename);
	data->matrix = (t_point **)malloc(sizeof(t_point *) * data->height);
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (t_point *)malloc(sizeof(t_point) * data->width);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Can't open the file\n", 20);
		exit(1);
	}
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i], i, line, data);
		free(line);
		i++;
	}
	close(fd);
}
