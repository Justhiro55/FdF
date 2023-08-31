/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:14:05 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/27 16:11:05 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error(int argc, char *argv[])
{
	int	len;

	len = 0;
	if (argc != 2)
	{
		ft_printf("usage: ./fdf map_file\n");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if ((open(argv[1], O_RDONLY, 0)) < 0 || len <= 4)
	{
		ft_printf("invalid file\n");
		exit(1);
	}
	if (argv[1][len - 1] != 'f' || argv[1][len - 2] != 'd' || argv[1][len
		- 3] != 'f' || argv[1][len - 4] != '.')
	{
		ft_printf("invalid file\n");
		exit(1);
	}
	return (1);
}
