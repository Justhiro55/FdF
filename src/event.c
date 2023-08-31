/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:42:42 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/26 16:26:31 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	zoomin(t_mappoint **map, t_fdf *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			map[i][j].x *= 1.1;
// 			map[i][j].y *= 1.1;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	zoomout(t_mappoint **map, t_fdf *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			map[i][j].x *= 0.9;
// 			map[i][j].y *= 0.9;
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	key_press(int keycode, t_fdf *data, t_mappoint **map)
{
	int	i;

	(void)data;
	(void)map;
	i = 0;
	if (keycode == KEY_UP)
	{
		ft_printf("UP key is pressed\n");
	}
	else if (keycode == KEY_DOWN)
	{
		ft_printf("DOWN key is pressed\n");
	}
	else if (keycode == KEY_ESC)
	{
		ft_printf("ESC key is pressed\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// int	mouse_press(int button, int x, int y, t_fdf *data)
// {
// 	(void)data;
// 	(void)x;
// 	(void)y;
// 	if (button ==
// 	return (0);
// }

int	close_window(void *param)
{
	(void)param;
	exit(0);
}
