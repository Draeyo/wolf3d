/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:55:51 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/21 14:55:52 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	complete_map(int map_tmp[20][20], t_wolf *wolf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
			MAP[x][y] = map_tmp[x][y];
	}
}