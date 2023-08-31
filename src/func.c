/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:35:36 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/31 14:47:58 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_numcount(char *str)
{
	int	count;

	count = 1;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
			count++;
			if (count == INT_MAX)
				exit(EXIT_FAILURE);
		}
		str++;
	}
	return (count - 1);
}

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_mod(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
