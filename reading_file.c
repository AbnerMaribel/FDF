/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:18:46 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/11 17:51:25 by amaribel         ###   ########.fr       */
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

void	fill_matrix(point *matrix_line, int line_num, char *line, fdf *data)
{
	char	**points;
	char **coord_color;
	int i;

	points = ft_split(line, ' ');
	i = 0;
	while (i < data->width)
	{
		coord_color = ft_split(points[i], ',');
		matrix_line[i].x = i;
		matrix_line[i].y = line_num;
		matrix_line[i].z = ft_atoi(coord_color[0]);
		if (coord_color[1] != NULL)
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

void	read_file(char *filename, fdf *data)
{
	int		i;
	int		i1;
	int		fd;
	char	*line;

	i1 = 0;
	data->height = get_height(filename);
	data->width = get_width(filename);
	data->matrix = (point **)malloc(sizeof(point *) * data->height);
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (point *)malloc(sizeof(point) * data->width);
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
		i1 = i;
		fill_matrix(data->matrix[i], i1, line, data);
		free(line);
		i++;
	}
	close(fd);
}
