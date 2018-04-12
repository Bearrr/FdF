/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:57:33 by ireva             #+#    #+#             */
/*   Updated: 2017/10/31 18:42:33 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bresenhem_norma(t_fdf *f_map, int color)
{
	f_map->d = (f_map->dx << 1) - f_map->dy;
	f_map->d1 = f_map->dx << 1;
	f_map->d2 = (f_map->dx - f_map->dy) << 1;
	mlx_pixel_put(f_map->mlx, f_map->win, f_map->x0, f_map->y0, color);
	f_map->x2 = f_map->x0;
	f_map->y2 = f_map->y0 + f_map->sy;
	while (f_map->p <= f_map->dy)
	{
		f_map->y2 += f_map->sy;
		if (f_map->d > 0)
		{
			f_map->d += f_map->d2;
			f_map->x2 += f_map->sx;
		}
		else
			f_map->d += f_map->d1;
		mlx_pixel_put(f_map->mlx, f_map->win, f_map->x2, f_map->y2, color);
		f_map->p++;
	}
}

void		bresenhem_norm(t_fdf *f_map, int color)
{
	f_map->d = (f_map->dy << 1) - f_map->dx;
	f_map->d1 = f_map->dy << 1;
	f_map->d2 = (f_map->dy - f_map->dx) << 1;
	mlx_pixel_put(f_map->mlx, f_map->win, f_map->x0, f_map->y0, color);
	f_map->x2 = f_map->x0 + f_map->sx;
	f_map->y2 = f_map->y0;
	while (f_map->p <= f_map->dx)
	{
		f_map->x2 += f_map->sx;
		if (f_map->d > 0)
		{
			f_map->d += f_map->d2;
			f_map->y2 += f_map->sy;
		}
		else
			f_map->d += f_map->d1;
		mlx_pixel_put(f_map->mlx, f_map->win, f_map->x2, f_map->y2, color);
		f_map->p++;
	}
}

void		bresenhem(t_fdf *f_map, int i, int j, int flag)
{
	if (flag == 1)
	{
		f_map->x0 = f_map->my_map[i][j].x;
		f_map->x1 = f_map->my_map[i][j + 1].x;
		f_map->y0 = f_map->my_map[i][j].y;
		f_map->y1 = f_map->my_map[i][j + 1].y;
	}
	if (flag == 2)
	{
		f_map->x0 = f_map->my_map[i][j].x;
		f_map->x1 = f_map->my_map[i + 1][j].x;
		f_map->y0 = f_map->my_map[i][j].y;
		f_map->y1 = f_map->my_map[i + 1][j].y;
	}
	f_map->dx = fabs(f_map->x1 - f_map->x0);
	f_map->dy = fabs(f_map->y1 - f_map->y0);
	f_map->sx = f_map->x1 >= f_map->x0 ? 1 : -1;
	f_map->sy = f_map->y1 >= f_map->y0 ? 1 : -1;
}

void		my_print(t_fdf *f_map, int i, int j, int flag)
{
	int		color;

	f_map->p = 1;
	color = f_map->my_map[i][j].color;
	bresenhem(f_map, i, j, flag);
	if (f_map->dy <= f_map->dx)
		bresenhem_norm(f_map, color);
	else
		bresenhem_norma(f_map, color);
}
