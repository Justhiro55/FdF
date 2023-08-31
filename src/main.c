/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:04:24 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/31 15:04:40 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mappoint	**init_map(t_fdf *data)
{
	int			i;
	t_mappoint	**map;

	map = (t_mappoint **)malloc(sizeof(t_mappoint *) * (data->height + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < data->height)
	{
		map[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * (data->width + 1));
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

void	set_default(t_fdf *param)
{
	param->scale = 8;
	param->z_scale = 2;
	param->angle = 0.65;
	param->win_x = 660;
	param->win_y = 880;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, param->win_y,
			"t_fdf");
}

int	adjust_scale(t_fdf *data)
{
	if (data->width / (data->win_x / 100) > data->height / (data->win_y / 100))
		data->scale = (data->win_x * 0.7) / (data->width);
	else
		data->scale = (data->win_y * 0.7) / (data->height);
	return (data->scale);
}

// int	adjust_zscale(t_fdf *data)
// {
// 	if (data->width / (data->win_x / 100) > data->height / (data->win_y / 100))
// 		data->z_scale = (data->win_x * 0.6) / (data->width);
// 	else
// 		data->z_scale = (data->win_y * 0.6) / (data->height);
// 	printf("data->z_scale:%d\n", data->z_scale);
// 	return (data->z_scale);
// }

int	main(int argc, char *argv[])
{
	t_fdf		*data;
	t_mappoint	**map;

	error(argc, argv);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		exit(1);
	set_default(data);
	map = read_file(argv[1], data);
	data->scale = adjust_scale(data);
	rotate_and_scale_map(map, data);
	draw_matrix(data, map);
	mlx_key_hook(data->win_ptr, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, NULL);
	mlx_loop(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q fdf");
// }
