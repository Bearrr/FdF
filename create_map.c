/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:28:20 by ireva             #+#    #+#             */
/*   Updated: 2017/10/30 21:11:25 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_num_c(char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t')
		i++;
	if (i == 6)
		return (3);
	if (i == 8)
		return (4);
	return (0);
}

int			check_color(char *line, t_fdf *f_map, int i, int j)
{
	int		a;

	a = 0;
	if (line[a + 1] == ',')
	{
		a = a + 2;
		if (ft_strncmp(&line[a], "0x", 2) == 0)
			a = a + 2;
		f_map->my_map[i][j].color = hex_to_decimal(&line[a], 6);
	}
	else
		f_map->my_map[i][j].color = hex_to_decimal("FFFFFF", 6);
	return (0);
}

int			create_cord_norma(t_fdf *f_map, int i, int j, char *line)
{
	f_map->my_map[i][j].y = (i - f_map->map_size / 2) * 1;
	f_map->my_map[i][j].x = (j - f_map->line_size / 2) * 1;
	f_map->my_map[i][j].z = (float)ft_atoi(&line[f_map->k]) * 7;
	check_color(&line[f_map->k], f_map, i, j);
	return (1);
}

int			create_coord(t_fdf *f_map, int fd)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	f_map->k = 0;
	while (get_next_line(fd, &line) > 0 && f_map->map_size > i)
	{
		while (line[f_map->k] || f_map->line_size > f_map->k)
		{
			while (line[f_map->k] == ' ' || line[f_map->k] == '\t')
				f_map->k++;
			if (line[f_map->k] != ' '
				&& line[f_map->k] != '\t' && line[f_map->k])
				j += create_cord_norma(f_map, i, j, line);
			while (line[f_map->k] != ' '
				&& line[f_map->k] != '\t' && line[f_map->k])
				f_map->k++;
		}
		f_map->k = 0;
		j = 0;
		i++;
	}
	return (0);
}

int			create_map(char *map, t_fdf *f_map)
{
	int		i;
	int		j;
	int		k;
	int		fd;

	i = 0;
	j = 0;
	fd = open(map, O_RDONLY);
	k = f_map->line_size;
	f_map->my_map = (t_cord**)malloc(sizeof(t_cord*) * f_map->map_size + 1);
	f_map->my_map[f_map->map_size] = NULL;
	while (f_map->map_size > i)
	{
		f_map->my_map[i] = (t_cord *)malloc(sizeof(t_cord) * k + 1);
		i++;
	}
	create_coord(f_map, fd);
	return (0);
}
