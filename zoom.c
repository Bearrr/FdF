/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:12:27 by ireva             #+#    #+#             */
/*   Updated: 2017/10/31 19:52:19 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_plus(t_fdf *f_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			f_map->my_map[i][j].x = ((f_map->my_map[i][j].x - 600) * 1.1);
			f_map->my_map[i][j].y = ((f_map->my_map[i][j].y - 600) * 1.1);
			f_map->my_map[i][j].x += 600;
			f_map->my_map[i][j].y += 600;
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}

void		zoom_minus(t_fdf *f_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	if (f_map->my_map[i][j].x >= 0 && f_map->my_map[i][j].y >= 1)
	{
		while (f_map->map_size > i)
		{
			while (f_map->line_size > j)
			{
				f_map->my_map[i][j].x = ((f_map->my_map[i][j].x - 600) / 1.1);
				f_map->my_map[i][j].y = ((f_map->my_map[i][j].y - 600) / 1.1);
				f_map->my_map[i][j].x += 600;
				f_map->my_map[i][j].y += 600;
				j++;
			}
			j = 0;
			i++;
		}
	}
	printim(f_map);
}

void		z_up(t_fdf *f_map, float k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			f_map->my_map[i][j].z = ((f_map->my_map[i][j].z - 600) * 1.1);
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}

void		z_down(t_fdf *f_map, float k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	mlx_clear_window(f_map->mlx, f_map->win);
	while (f_map->map_size > i)
	{
		while (f_map->line_size > j)
		{
			f_map->my_map[i][j].z = ((f_map->my_map[i][j].z - 600) / 1.1);
			j++;
		}
		j = 0;
		i++;
	}
	printim(f_map);
}
