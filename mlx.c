/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:30:00 by ireva             #+#    #+#             */
/*   Updated: 2017/10/31 19:44:06 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		printim_norma(t_fdf *f_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (f_map->map_size > i + 1)
	{
		while (f_map->line_size > j)
		{
			my_print(f_map, i, j, 2);
			j++;
		}
		j = 0;
		i++;
	}
}

void		printim(t_fdf *f_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j + 1)
		{
			my_print(f_map, i, j, 1);
			j++;
		}
		j = 0;
		i++;
	}
	printim_norma(f_map);
}

int			key_pressed(int x, t_fdf *f_map)
{
	if (x == 53)
		exit(1);
	if (x == 125)
		turning_x_minus(f_map, -0.01);
	if (x == 126)
		turning_x(f_map, 0.01);
	if (x == 123)
		turning_z_minus(f_map, -0.01);
	if (x == 124)
		turning_z(f_map, 0.01);
	if (x == 69)
		zoom_plus(f_map);
	if (x == 78)
		zoom_minus(f_map);
	if (x == 262)
		z_up(f_map, 0.01);
	if (x == 269)
		z_down(f_map, 0.01);
	return (0);
}

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int			mlx(t_fdf *f_map)
{
	f_map->mlx = mlx_init();
	f_map->win = mlx_new_window(f_map->mlx, 1200, 1200, "Fdf");
	to_center(f_map);
	printim(f_map);
	mlx_hook(f_map->win, 2, 5, key_pressed, f_map);
	mlx_hook(f_map->win, 17, 1L << 17, exit_x, f_map);
	mlx_loop(f_map->mlx);
	return (0);
}
