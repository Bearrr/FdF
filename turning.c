/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:48:30 by ireva             #+#    #+#             */
/*   Updated: 2017/10/30 21:11:53 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		to_center(t_fdf *f_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			f_map->my_map[i][j].y = f_map->my_map[i][j].y + 600;
			f_map->my_map[i][j].x = f_map->my_map[i][j].x + 600;
			j++;
		}
		j = 0;
		i++;
	}
}

void		turning_x(t_fdf *f_map, float k)
{
	int		i;
	int		j;
	float	y;
	float	z;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			z = f_map->my_map[i][j].z - 600;
			y = f_map->my_map[i][j].y - 600;
			f_map->my_map[i][j].y = (y * (float)cos(k) + z * (float)sin(k));
			f_map->my_map[i][j].z = (-y * (float)sin(k) + z * (float)cos(k));
			f_map->my_map[i][j].y += 600;
			f_map->my_map[i][j].z += 600;
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}

void		turning_x_minus(t_fdf *f_map, float k)
{
	int		i;
	int		j;
	float	y;
	float	z;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			z = f_map->my_map[i][j].z - 600;
			y = f_map->my_map[i][j].y - 600;
			f_map->my_map[i][j].y = (y * (float)cos(k) + z * (float)sin(k));
			f_map->my_map[i][j].z = (-y * (float)sin(k) + z * (float)cos(k));
			f_map->my_map[i][j].y += 600;
			f_map->my_map[i][j].z += 600;
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}

void		turning_z_minus(t_fdf *f_map, float k)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			y = f_map->my_map[i][j].y - 600;
			x = f_map->my_map[i][j].x - 600;
			f_map->my_map[i][j].x = x * (float)cos(k) + y * (float)sin(k);
			f_map->my_map[i][j].y = -x * (float)sin(k) + y * (float)cos(k);
			f_map->my_map[i][j].y += 600;
			f_map->my_map[i][j].x += 600;
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}

void		turning_z(t_fdf *f_map, float k)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			y = f_map->my_map[i][j].y - 600;
			x = f_map->my_map[i][j].x - 600;
			f_map->my_map[i][j].x = x * (float)cos(k) + y * (float)sin(k);
			f_map->my_map[i][j].y = -x * (float)sin(k) + y * (float)cos(k);
			f_map->my_map[i][j].x += 600;
			f_map->my_map[i][j].y += 600;
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}
