/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:20:23 by ireva             #+#    #+#             */
/*   Updated: 2017/10/31 18:43:09 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_cord
{
	float			x;
	float			y;
	float			z;
	int				proz;
	int				blue;
	int				green;
	int				red;
	int				color;
}					t_cord;

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	float			x0;
	float			x1;
	float			y0;
	float			y1;
	int				d;
	int				d1;
	int				d2;
	int				x2;
	int				y2;
	int				line_size;
	int				map_size;
	void			*win;
	void			*mlx;
	int				k;
	int				p;
	t_cord			**my_map;
}					t_fdf;

int					validation(char *map, t_fdf *f_map);
int					create_map(char *map, t_fdf *f_map);
int					mlx(t_fdf *f_map);
void				turning_x(t_fdf *f_map, float k);
void				to_center(t_fdf *f_map);
void				turning_x_minus(t_fdf *f_map, float k);
void				turning_z_minus(t_fdf *f_map, float k);
void				turning_z(t_fdf *f_map, float k);
void				zoom_plus(t_fdf *f_map);
void				zoom_minus(t_fdf *f_map);
void				turning_y(t_fdf *f_map, float k);
void				z_up(t_fdf *f_map, float k);
void				z_down(t_fdf *f_map, float k);
int					hex_to_decimal(char *hex, int len);
void				bresenhem_norma(t_fdf *f_map, int color);
void				bresenhem_norm(t_fdf *f_map, int color);
void				bresenhem(t_fdf *f_map, int i, int j, int flag);
void				my_print(t_fdf *f_map, int i, int j, int flag);
void				printim(t_fdf *f_map);

#endif
