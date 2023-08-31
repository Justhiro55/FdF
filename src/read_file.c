/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:34:44 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/31 15:06:38 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_height_util(char *line)
{
	int	i;

	i = 0;
	if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '-')
		exit(1);
	while (line[i] != '\0' && line[i] != '\n' && line[i] != 10)
	{
		if (*line == 44)
			exit(1);
		i++;
	}
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (height == INT_MAX)
			exit(EXIT_FAILURE);
		get_height_util(line);
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	int		tmp;

	fd = open(file_name, O_RDONLY, 0);
	tmp = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = ft_numcount(line);
		if (tmp != -1 && tmp != width)
		{
			ft_printf("Error: invalid input file\n");
			exit(1);
		}
		tmp = width;
		free(line);
	}
	close(fd);
	return (width);
}

void	get_coordinate(t_fdf *data, t_mappoint **map, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	**nums;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		line = get_next_line(fd);
		nums = ft_split(line, ' ');
		while (j < data->width)
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].z = ft_atoi(nums[j]);
			j++;
		}
		free_nums(nums);
		free(line);
		i++;
	}
	close(fd);
}

t_mappoint	**read_file(char *file_name, t_fdf *data)
{
	int			i;
	int			ratio;
	t_mappoint	**map;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height == 0 && data->width == 0)
	{
		ft_printf("invalid file\n");
		exit(1);
	}
	map = init_map(data);
	if (map == NULL)
		exit(1);
	ratio = ft_min(data->win_x / data->width, data->win_y / data->height);
	get_coordinate(data, map, file_name);
	if (map == NULL)
		exit(1);
	return (map);
}
