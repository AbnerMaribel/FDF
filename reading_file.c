/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:18:46 by amaribel          #+#    #+#             */
/*   Updated: 2022/03/09 13:45:46 by amaribel         ###   ########.fr       */
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

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
	}
	ft_free_char(nums);
}

void	read_file(char *filename, fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_height(filename);
	data->width = get_width(filename);
	data->matrix = (int **)malloc(sizeof(int *) * data->height);
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * data->width);
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
		fill_matrix(data->matrix[i++], line);
		free(line);
	}
	close(fd);
	data->matrix[i] = 0;
}

t_point **coord_matrix(fdf *data)
{
	t_point **crd_matrix;
	int i;
	int j;

	crd_matrix = (t_point **)malloc(sizeof(t_point *) * data->height);
	i = 0;
	while (i < data->height)
		crd_matrix[i++] = (t_point *)malloc(sizeof(t_point) * data->width);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			crd_matrix[i][j].x = j;
			crd_matrix[i][j].y = i;
			crd_matrix[i][j].z = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (crd_matrix);
}