/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:04:37 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/31 14:46:51 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125

typedef struct s_mappoint
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}				t_mappoint;

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
}				t_fdf;

t_mappoint		**read_file(char *file_name, t_fdf *data);
int				ft_numcount(char *str);
int				error_atoi(char *nums);
int				error(int argc, char *argv[]);
void			draw_line_mlx(t_fdf *data);
int				draw_matrix(t_fdf *data, t_mappoint **map);
void			scalePoint(t_mappoint *point, double scaleFactor);
int				ft_max(float a, float b);
float			ft_mod(float num);
int				ft_min(int a, int b);
void			rotate_and_scale_map(t_mappoint **map, t_fdf *data);
int				key_press(int keycode, t_fdf *data, t_mappoint **map);
int				ft_abs(int num);
void			tail_map(t_mappoint **map, t_fdf *data);
void			free_map(t_mappoint **map, t_fdf *data);
void			free_nums(char **nums);
void			set_default(t_fdf *param);
int				mouse_press(int button, int x, int y, t_fdf *data);
int				close_window(void *param);
t_mappoint		**init_map(t_fdf *data);

#endif