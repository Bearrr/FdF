/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:43:24 by ireva             #+#    #+#             */
/*   Updated: 2017/10/30 21:12:07 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			hex_to_decimal(char *hex, int len)
{
	int		i;
	int		decimal;

	i = 0;
	decimal = 0;
	while (i < len)
	{
		if (hex[i] <= 57)
			decimal += (hex[i] - 48) * (1 << (4 * (len - 1 - i)));
		else
			decimal += (hex[i] - 55) * (1 << (4 * (len - 1 - i)));
		i++;
	}
	return (decimal);
}
