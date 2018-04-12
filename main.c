/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:22:49 by ireva             #+#    #+#             */
/*   Updated: 2017/10/30 21:11:01 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	f_map;

	if (argc != 2)
		write(1, "usage : wrong arguments", 23);
	if (validation(argv[1], &f_map) == 0)
		create_map(argv[1], &f_map);
	mlx(&f_map);
	return (0);
}
