/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:23:51 by ireva             #+#    #+#             */
/*   Updated: 2017/10/31 18:39:22 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_length(char *line, t_fdf *t_map)
{
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ' ' && line[i] != '\t' && line[i])
			length++;
		while (line[i] != ' ' && line[i] != '\t' && line[i])
			i++;
	}
	t_map->map_size++;
	return (length);
}

void		check_size(char *line, int fd, t_fdf *f_map)
{
	int		length;

	if ((get_next_line(fd, &line) < 0))
	{
		write(1, "Wrong map, GL", 13);
		exit(-1);
	}
	else
	{
		f_map->line_size = check_length(line, f_map);
		while ((get_next_line(fd, &line) > 0))
		{
			length = check_length(line, f_map);
			if (f_map->line_size > length)
			{
				write(1, "Wrong map, GL", 13);
				free(line);
				close(fd);
				exit(-1);
			}
			if (line != NULL)
				free(line);
		}
	}
}

void		init(t_fdf *f_map)
{
	f_map->line_size = 0;
	f_map->x = 0;
	f_map->y = 0;
	f_map->z = 0;
	f_map->map_size = 0;
}

int			validation(char *map, t_fdf *f_map)
{
	int		fd;
	char	*line;

	line = NULL;
	init(f_map);
	if ((fd = open(map, O_RDONLY)) == -1)
	{
		ft_putendl("open failed!!!");
		return (-1);
	}
	check_size(line, fd, f_map);
	return (0);
}
