/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:53:15 by ireva             #+#    #+#             */
/*   Updated: 2017/02/13 13:49:06 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			**check_fd(int fd, t_lists **list)
{
	t_lists *ptr;

	ptr = *list;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (&(ptr->line3));
		ptr = ptr->next;
	}
	ptr = (t_lists *)malloc(sizeof(t_lists));
	ptr->fd = fd;
	ptr->line3 = NULL;
	ptr->next = *list;
	*list = ptr;
	return (&(ptr->line3));
}

void			get_next(char **line3, char *buff)
{
	char *line2;

	line2 = NULL;
	if (*line3 == NULL)
		*line3 = ft_strdup(buff);
	else
	{
		line2 = ft_strdup(*line3);
		free(*line3);
		*line3 = ft_strjoin(line2, buff);
		free(line2);
	}
}

size_t			check_enter(char *line3)
{
	size_t		i;

	i = 0;
	while (line3[i] != '\n')
		i++;
	i++;
	return (i);
}

int				wr_line(char **line3, char **line)
{
	size_t	i;

	i = 0;
	if (!ft_strchr(*line3, '\n'))
	{
		*line = ft_strnew(ft_strlen(*line3));
		*line = ft_strcpy(*line, *line3);
		free(*line3);
		*line3 = NULL;
		return (1);
	}
	i = check_enter(*line3);
	*line = ft_strnew(i - 1);
	*line = ft_strncpy(*line, *line3, i - 1);
	if (i < ft_strlen(*line3))
		*line3 = ft_strsub(*line3, i, (ft_strlen(*line3) - i));
	else
	{
		free(*line3);
		*line3 = NULL;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	ssize_t				numread;
	char				**line3;
	static t_lists		*list;

	if (BUFF_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	line3 = check_fd(fd, &list);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (*line3)
		if (ft_strchr(*line3, '\n'))
			return (wr_line(line3, line));
	while ((numread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		get_next(line3, buff);
		if (ft_strchr(*line3, '\n'))
			break ;
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (numread < 0)
		return (-1);
	if (numread < BUFF_SIZE && (*line3 == NULL || !ft_strlen(*line3)))
		return (0);
	return (wr_line(line3, line));
}
