/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:04:38 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/27 16:27:40 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(t_mappoint map1, t_mappoint map2)
{
	if (map1.z > 0 || map2.z > 0)
	{
		return (0x00ffff);
	}
	else if (map1.z < 0)
		return (0xffa500);
	else
		return (0xffffff);
}

void	put_pixel_to_image(t_fdf *data, int x, int y, int color)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*pixel;

	if (x >= 0 && x < data->win_x && y >= 0 && y < data->win_y)
	{
		bpp = 0;
		size_line = 0;
		endian = 0;
		data->img_data = mlx_get_data_addr(data->img_ptr, &bpp, &size_line,
				&endian);
		if (data->img_data)
		{
			pixel = data->img_data + (x * 4) + (y * data->win_x * 4);
			*((int *)pixel) = color;
		}
	}
}

void	line(t_mappoint map1, t_mappoint map2, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		max;

	x = map1.x;
	y = map1.y;
	x_step = (map2.x - x);
	y_step = (map2.y - y);
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	while ((int)(x - map2.x) || (int)(y - map2.y))
	{
		put_pixel_to_image(data, x, y, get_color(map1, map2));
		x += x_step / max;
		y += y_step / max;
	}
}

int	draw_matrix(t_fdf *data, t_mappoint **map)
{
	int	i;
	int	j;

	i = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j + 1 < data->width)
				line(map[i][j], map[i][j + 1], data);
			if (i + 1 < data->height)
				line(map[i][j], map[i + 1][j], data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	return (0);
}
