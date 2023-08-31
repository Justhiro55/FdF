/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:33:33 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/27 16:18:33 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_to_center(t_mappoint **map, t_fdf *data)
{
	int	i;
	int	j;
	int	diff_x;
	int	diff_y;

	diff_x = data->win_x / 2 - map[data->height / 2][data->width / 2].x;
	diff_y = data->win_y / 11 * 6 - map[data->height / 2][data->width / 2].y;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			map[i][j].x += diff_x;
			map[i][j].y += diff_y;
			j++;
		}
		i++;
	}
}

// void	tail_map(t_mappoint **map, t_fdf *data)
// {
// 	(void)map;
// 	if (data->width / (data->win_x / 100) > data->height / (data->win_y / 100))
// 		data->scale = (data->win_x * 0.9) / (data->width);
// 	else
// 		data->scale = (data->win_y * 0.9) / (data->height);
// }

void	rotate_and_scale_map(t_mappoint **map, t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			map[i][j].x *= data->scale * 0.55;
			map[i][j].y *= data->scale * 0.55;
			map[i][j].z *= data->scale * 0.3;
			map[i][j].x = map[i][j].x * cos(data->angle) - map[i][j].y
				* sin(data->angle);
			map[i][j].y = map[i][j].x * sin(data->angle) + map[i][j].y
				* cos(data->angle) - map[i][j].z;
			j++;
		}
		i++;
	}
	move_to_center(map, data);
}
